#include "LuaScript.h"
#include "TextureManager.h"

using namespace std;
using namespace sf;

TextureManager *TextureManager::instance = nullptr;

luaL_Reg TextureManager::library[] =
{
	"load", TextureManager::load_texture_feature,

	nullptr, nullptr
};

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (auto texture : textures)
	{
		delete texture;
	}
}

Texture *TextureManager::load_texture(const char * filename)
{
	sf::Texture *texture = new sf::Texture();
	if (!texture->loadFromFile(filename))
	{
		delete texture;
		return nullptr;
	}

	textures.push_back(texture);
	return texture;
}

TextureManager * TextureManager::getInstance()
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

int TextureManager::open_library(lua_State * state)
{
	luaL_newlib(state, library);
	return 1;
}

int TextureManager::load_texture_feature(lua_State * state)
{
	auto text = lua_tostring(state, 1);
	auto texture = instance->load_texture(text);
	if (texture)
		LuaScript::create_texture_store(state, texture);
	return 1;
}
