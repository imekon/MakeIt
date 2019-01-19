#include "LuaScript.h"
#include "TextureManager.h"

#include <RefCountedPtr.h>

using namespace std;
using namespace luabridge;
using namespace MakeIt;

TextureManager *TextureManager::instance = nullptr;

TextureManager::TextureManager()
{
}

void TextureManager::add_texture(Texture *texture)
{
	textures.push_back(texture);
}

TextureManager * TextureManager::get_instance()
{
	if (instance == nullptr)
		instance = new TextureManager();

	return instance;
}

void TextureManager::shutdown()
{
	if (instance)
		delete instance;

	instance = nullptr;
}

