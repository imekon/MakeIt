#pragma once

#include <vector>
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

		Vector2 get_origin() const { return _origin; }
		void set_origin(Vector2 vector);
		void set_texture(Texture *texture);

		int get_z() const { return _z; }
		void set_z(int z) { _z = z; }

		void sort();

		void draw(sf::RenderWindow *window) override;

		static void register_class(lua_State *state);

	private:
		int _z;
		sf::Sprite _sprite;
		Vector2 _origin;
	};
}