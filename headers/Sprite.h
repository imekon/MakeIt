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

		void set_position(Vector2 vector) override;
		void set_global_position(Vector2 vector) override;
		void set_scale(Vector2 vector) override;
		void set_rotate(float angle) override;

		Vector2 get_origin() const { return _origin; }
		void set_origin(Vector2 vector);
		void set_texture(Texture *texture);

		void draw(sf::RenderWindow *window) override;

		static void register_class(lua_State *state);

	private:
		sf::Sprite _sprite;
		Vector2 _origin;
	};
}