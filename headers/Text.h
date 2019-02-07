#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <SFML/Graphics.hpp>

#include "Node2D.h"
#include "Font.h"

namespace MakeIt
{
	class Text : public Node2D
	{
	public:
		Text();
		virtual ~Text();

		void set_font(Font *font);
		void set_string(const char *text);

		static void register_class(lua_State *state);

	private:
		sf::Text *_text;
	};
}