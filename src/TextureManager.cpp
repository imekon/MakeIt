#include "LuaScript.h"
#include "TextureManager.h"

#include <RefCountedPtr.h>

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

	TextureManager::getInstance()->add_texture(this);

	return true;
}

int Texture::get_width() const
{
	if (_texture)
	{
		auto size = _texture->getSize();
		return size.x;
	}

	return 0;
}

int Texture::get_height() const
{
	if (_texture)
	{
		auto size = _texture->getSize();
		return size.y;
	}

	return 0;
}

TextureManager::TextureManager()
{
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

void TextureManager::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Texture>("Texture")
		.addConstructor<void (*)(void), RefCountedPtr<Texture>>()
		.addFunction("load", &Texture::load)
		.addProperty("width", &Texture::get_width)
		.addProperty("height", &Texture::get_height)
		.endClass();
}

