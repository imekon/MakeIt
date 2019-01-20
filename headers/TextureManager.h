#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <vector>
#include <SFML/Graphics.hpp>

#include "Texture.h"

namespace MakeIt
{
	class TextureManager
	{
	public:
		TextureManager();

		void add_texture(Texture *texture);

		static TextureManager *get_instance();
		static void shutdown();

	private:
		static TextureManager *instance;

		std::vector<Texture *> textures;
	};
}
