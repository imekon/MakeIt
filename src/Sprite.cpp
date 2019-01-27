#include <algorithm>

#include "LuaScript.h"
#include "TextureManager.h"
#include "Sprite.h"

using namespace luabridge;
using namespace MakeIt;

Sprite::Sprite() : _origin(0.0f, 0.0f)
{
}

Sprite::~Sprite()
{
}

void Sprite::set_global_position(Vector2 vector)
{
	Node2D::set_global_position(vector);

	_sprite.setPosition(_global_position.get_x() + _position.get_x(), _global_position.get_y() + _position.get_y());
}

void Sprite::set_position(MakeIt::Vector2 vector)
{
	Node2D::set_position(vector);

	_sprite.setPosition(_global_position.get_x() + _position.get_x(), _global_position.get_y() + _position.get_y());
}

void Sprite::set_scale(MakeIt::Vector2 vector)
{
	Node2D::set_scale(vector);
	_sprite.setScale(vector.get_x(), vector.get_y());
}

void Sprite::set_rotate(float angle)
{
	Node2D::set_rotate(angle);
	_sprite.setRotation(angle);
}

void Sprite::set_origin(Vector2 vector)
{
	_origin = vector;
	_sprite.setOrigin(_origin.get_x(), _origin.get_y());
}

void Sprite::set_texture(Texture * texture)
{
	if (texture == nullptr)
		return;

	_sprite.setTexture(*texture->get_texture());
}

void Sprite::draw(sf::RenderWindow *window)
{
	if (_visible)
	{
		Node2D::draw(window);
		window->draw(_sprite);
	}
}

void Sprite::register_class(lua_State * state)
{
	getGlobalNamespace(state).deriveClass<Sprite, Node2D>("Sprite")
		.addConstructor<void(*) (void), RefCountedPtr<Sprite>>()
		.addProperty("origin", &Sprite::get_origin, &Sprite::set_origin)
		.addFunction("set_texture", &Sprite::set_texture)
		.endClass();
}
