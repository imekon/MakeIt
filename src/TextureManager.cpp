#include "LuaScript.h"
#include "TextureManager.h"

using namespace std;
using namespace luabridge;
using namespace MakeIt;

TextureManager *TextureManager::instance = nullptr;

Texture::Texture() : _texture(nullptr)
{
}

Texture::~Texture()
{
	if (_texture)
		delete _texture;
}

bool Texture::load(const char * filename)
{
	_texture = new sf::Texture();
	if (!_texture->loadFromFile(filename))
	{
		delete _texture;
		_texture = nullptr;
		return false;
	}

	return true;
}

Texture * Texture::create(const char * filename)
{
	auto texture = new Texture();
	texture->load(filename);
	TextureManager::getInstance()->add_texture(texture);
	return texture;
}

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

void TextureManager::add_texture(Texture *texture)
{
	textures.push_back(texture);
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

void TextureManager::open_library(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Texture>("Texture")
		.addStaticFunction("create", Texture::create)
		.endClass();
}

