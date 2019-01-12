#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "Console.h"
#include "LuaScript.h"
#include "TextureManager.h"

int main()
{
	auto console = Console::getInstance();
	auto texture_manager = TextureManager::getInstance();

	LuaScript::initialise(console);
	auto loaded = LuaScript::load_file("scripts\\game.lua");

	int width = 1024;
	int height = 600;
	char title[256];
	strcpy_s(title, "The Make It game engine!");

	if (loaded)
		LuaScript::process_configuration(width, height, title, 256);

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

		ImGui::Begin("Console");
		ImGui::BeginChild("console text", ImVec2(0, 200));
		for (auto & content : console->get_content())
		{
			ImGui::TextColored(content.colour, content.text.c_str());
			if (!content.newLine)
				ImGui::SameLine();
		}

		ImGui::EndChild();
		ImGui::Spacing();
		if (ImGui::InputText("console input", buffer, IM_ARRAYSIZE(buffer), ImGuiInputTextFlags_EnterReturnsTrue))
		{
			LuaScript::process(buffer);
			buffer[0] = 0;
		}

		ImGui::End();

		ImGui::ShowDemoWindow();

		window.clear();
		ImGui::SFML::Render(window);
		window.display();
	}

	LuaScript::shutdown();

	ImGui::SFML::Shutdown();

	delete console;
	TextureManager::shutdown();

	return 0;
}