#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "LuaScript.h"

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

		ImGui::Begin("Hello, world!");
		ImGui::Button("Look at this pretty button");
		ImGui::End();

		window.clear();
		ImGui::SFML::Render(window);
		window.display();
	}

	LuaScript::shutdown();

	ImGui::SFML::Shutdown();

	return 0;
}