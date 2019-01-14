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

		static Texture *create(const char *filename);

	private:
		sf::Texture *_texture;
	};

	class TextureManager
	{
	public:
		TextureManager();
		~TextureManager();

		void add_texture(Texture *texture);

		static TextureManager *getInstance();
		static void shutdown();
		static void open_library(lua_State *state);

	private:
		static TextureManager *instance;

		std::vector<Texture *> textures;
	};
}
