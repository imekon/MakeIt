#include "Engine.h"

#include "LuaScript.h"
#include "TextureManager.h"

#include <RefCountedPtr.h>

using namespace std;
using namespace luabridge;
using namespace MakeIt;

Texture::Texture() : _texture(nullptr)
{
	ENGINE_CONSTRUCTOR(this);
}

Texture::~Texture()
{
	if (_texture)
		delete _texture;

	ENGINE_DESTRUCTOR(this);
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

	TextureManager::get_instance()->add_texture(this);

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

void Texture::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Texture>("Texture")
		.addConstructor<void(*)(void), RefCountedPtr<Texture>>()
		.addFunction("load", &Texture::load)
		.addProperty("width", &Texture::get_width)
		.addProperty("height", &Texture::get_height)
		.endClass();
}

