#pragma once

#include <lua.hpp>

#include <vector>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	sf::Texture *load_texture(const char *filename);

	static TextureManager *getInstance();
	static void shutdown();
	static int open_library(lua_State *state);

private:
	static TextureManager *instance;

	std::vector<sf::Texture *> textures;

	static luaL_Reg library[];
	static int load_texture_feature(lua_State *state);
};