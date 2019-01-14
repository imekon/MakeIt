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

		void set_translate(MakeIt::Vector2 vector) override;
		void set_scale(MakeIt::Vector2 vector) override;
		void set_rotate(float angle) override;
		void set_texture(sf::Texture *texture);

		static int open_library(lua_State *state);

	private:
		sf::Sprite sprite;

		static luaL_Reg library[];

		static int create_feature(lua_State *state);
		static int set_texture_feature(lua_State *state);
	};
}