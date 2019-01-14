#pragma once

#include <lua.hpp>
#include <SFML/Graphics.hpp>

#include "Node2D.h"

namespace MakeIt
{
	class Sprite : public Node2D
	{
	public:
		Sprite();
		virtual ~Sprite();

		void set_position(MakeIt::Vector2 vector) override;
		void set_scale(MakeIt::Vector2 vector) override;
		void set_rotate(float angle) override;
		void set_texture(Texture *texture);

		static void open_library(lua_State *state);

	private:
		sf::Sprite sprite;

		static Sprite *create();
	};
}