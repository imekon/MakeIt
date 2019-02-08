#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <SFML/Graphics.hpp>

#include "Node2D.h"
#include "Font.h"

namespace MakeIt
{
	class Colour;

	class Text : public Node2D
	{
	public:
		Text();
		virtual ~Text();

		const char *get_type_name() const override { return "Text"; }

		void set_font(Font *font);
		void set_string(const char *text);
		void set_character_size(int size);
		void set_fill_colour(Colour *colour);

		void set_position(const Vector2 *vector) override;

		void draw(sf::RenderWindow *window) override;

		static void register_class(lua_State *state);

	private:
		sf::Text *_text;
	};
}