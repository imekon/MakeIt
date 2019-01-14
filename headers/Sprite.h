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

		int get_z() const { return _z; }
		void set_z(int z) { _z = z; }

		static void open_library(lua_State *state);

	private:
		int _z;
		sf::Sprite _sprite;

		static Sprite *create();
	};
}