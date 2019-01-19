#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "Console.h"
#include "LuaScript.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Scene.h"

using namespace MakeIt;

static void traverse_scene_tree(Node *node)
{
	for (auto child : node->get_children())
	{
		if (ImGui::TreeNode(child->get_name()))
		{
			traverse_scene_tree(child);

			ImGui::TreePop();
		}
	}
}

int main()
{
	auto console = Console::getInstance();
	auto texture_manager = TextureManager::getInstance();

	LuaScript::initialise(console);
	auto loaded = LuaScript::load_file("scripts/game.lua");

	int width = 1024;
	int height = 600;
	char title[256];
	strcpy_s(title, "The Make It game engine!");

	if (loaded)
		LuaScript::process_configuration(width, height, title, 256);

	LuaScript::execute_function("game_startup");

	sf::RenderWindow window(sf::VideoMode(width, height), title);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);

	char buffer[256];
	buffer[0] = 0;

	auto showConsole = true;

	console->print("MakeIt Game Engine\n\nCopyright (C) 2019 Pete Goodwin\n\n");

	auto root = Scene::get_root();

	sf::Clock deltaClock;
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			ImGui::SFML::ProcessEvent(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::EventType::KeyPressed:
				if (event.key.code == sf::Keyboard::Quote)
					showConsole = true;
				break;
			}
		}

		auto delta = deltaClock.restart();
		auto fps = 1.0f / delta.asSeconds();
		ImGui::SFML::Update(window, delta);

		if (showConsole)
		{
			ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
			ImGui::Begin("Console");

			ImGui::BeginChild("buttons", ImVec2(520, 20));

			if (ImGui::Button("Close"))
				showConsole = false;

			ImGui::SameLine();
			ImGui::Button("Edit");
			ImGui::SameLine();
			ImGui::LabelText("fps", "FPS: %1.1f", fps);
			ImGui::EndChild();

			const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
			ImGui::BeginChild("console text", ImVec2(0, -footer_height_to_reserve));
			for (auto & content : console->get_content())
			{
				ImGui::TextColored(content.colour, content.text.c_str());
				if (!content.newLine)
					ImGui::SameLine();
			}

			if (console->get_scroll_to_bottom())
				ImGui::SetScrollHereY(1.0f);

			console->clear_scroll_to_bottom();
			ImGui::EndChild();

			//ImGui::Separator();
			ImGui::Spacing();
			bool reclaim_focus = false;
			if (ImGui::InputText("Lua Input", buffer, IM_ARRAYSIZE(buffer), ImGuiInputTextFlags_EnterReturnsTrue))
			{
				LuaScript::process(buffer);
				buffer[0] = 0;
				reclaim_focus = true;
			}

			ImGui::SetItemDefaultFocus();
			if (reclaim_focus)
				ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

			ImGui::End();
			ImGui::ShowDemoWindow();
		}

		ImGui::SetNextWindowSize(ImVec2(400, 300), ImGuiCond_FirstUseEver);
		ImGui::Begin("Project");
		if (ImGui::TreeNode("Scene"))
		{
			if (root)
				traverse_scene_tree(root);

			ImGui::TreePop();
		}
		ImGui::End();

		LuaScript::execute_function("game_run", delta.asSeconds());

		window.clear();
		if (root)
			root->draw(&window);
		ImGui::SFML::Render(window);
		window.display();
	}

	LuaScript::execute_function("game_shutdown");

	ImGui::SFML::Shutdown();

	Console::shutdown();
	TextureManager::shutdown();

	LuaScript::shutdown();

	return 0;
}