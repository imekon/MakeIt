#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "Console.h"
#include "LuaScript.h"

static char console_buffer[4096];

void console_print(const char *text)
{
	strcat_s(console_buffer, text);
}

void console_clear()
{
	console_buffer[0] = 0;
}

int main()
{
	LuaScript::initialise();

	int width = 1024;
	int height = 600;
	char title[256];
	strcpy_s(title, "The Make It game engine!");

	sf::RenderWindow window(sf::VideoMode(width, height), title);
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);

	char buffer[256];
	buffer[0] = 0;

	strcat_s(console_buffer, "MakeIt Game Engine\n\nCopyright (c) 2018 Pete Goodwin\n");

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
		ImGui::Text(console_buffer);
		ImGui::EndChild();
		ImGui::Spacing();
		ImGui::InputText("console input", buffer, IM_ARRAYSIZE(buffer));
		ImGui::End();

		ImGui::ShowDemoWindow();

		window.clear();
		ImGui::SFML::Render(window);
		window.display();
	}

	LuaScript::shutdown();

	ImGui::SFML::Shutdown();

	return 0;
}