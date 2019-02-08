#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <SFML/Graphics.hpp>

#include "Object.h"

namespace MakeIt
{
	class Colour : public Object
	{
	public:
		Colour();

		const char *get_type_name() const override { return "Colour"; }

		int red() const { return _colour.r; }
		int green() const { return _colour.g; }
		int blue() const { return _colour.b; }
		int alpha() const { return _colour.a; }

		sf::Color get_colour() const { return _colour; }

		static Colour *from_rgba(int red, int green, int blue, int alpha);
		static Colour *from_rgb(int red, int green, int blue);
		static Colour *from_name(const char *name);

		static void register_class(lua_State *state);

	private:
		sf::Color _colour;
	};
}