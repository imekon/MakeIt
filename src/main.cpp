#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "Console.h"
#include "LuaScript.h"
#include "TextureManager.h"

using namespace MakeIt;

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
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);

	char buffer[256];
	buffer[0] = 0;

	console->print("MakeIt Game Engine\n\nCopyright (c) 2019 Pete Goodwin\n\n");

	sf::Clock deltaClock;
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
		ImGui::Begin("Console");
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

		LuaScript::execute_function("game_run");

		window.clear();
		ImGui::SFML::Render(window);
		window.display();
	}

	LuaScript::execute_function("game_shutdown");
	LuaScript::shutdown();

	ImGui::SFML::Shutdown();

	Console::shutdown();
	TextureManager::shutdown();

	return 0;
}