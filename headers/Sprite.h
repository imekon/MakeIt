#pragma once

#include <SFML/Graphics.hpp>

#include "Node2D.h"

namespace MakeIt
{
	class Sprite : public Node2D
	{
	public:
		Sprite();
		virtual ~Sprite();

	private:
		sf::Sprite sprite;
	};
}