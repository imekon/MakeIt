#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <SFML/Graphics.hpp>

#include "Object.h"

namespace MakeIt
{
	class Font : public Object
	{
	public:
		Font();
		virtual ~Font();

		const char *get_type_name() const override { return "Font"; }

		sf::Font *get_font() const { return _font; }
		bool load(const char *filename);

		static void register_class(lua_State *state);

	private:
		sf::Font *_font;
	};
}