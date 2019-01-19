#pragma once

#include <lua.hpp>
#include <LuaBridge.h>

#include <vector>
#include <SFML/Graphics.hpp>

namespace MakeIt
{
	class Texture
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
