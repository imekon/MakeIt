#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <vector>
#include <SFML/Graphics.hpp>

#include "Object.h"

namespace MakeIt
{
	class Texture : public Object
	{
	public:
		Texture();
		virtual ~Texture();

		sf::Texture *get_texture() const { return _texture; }
		bool load(const char *filename);
		int get_width() const;
		int get_height() const;

		static void register_class(lua_State *state);

	private:
		sf::Texture *_texture;
	};
}
