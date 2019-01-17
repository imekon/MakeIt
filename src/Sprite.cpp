#include <algorithm>

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include "LuaScript.h"
#include "TextureManager.h"
#include "Sprite.h"

using namespace luabridge;
using namespace MakeIt;

Sprite::Sprite() : _origin(0.0f, 0.0f), _z(0)
{
}

Sprite::~Sprite()
{
}

void Sprite::set_position(MakeIt::Vector2 vector)
{
	Node2D::set_position(vector);

	_sprite.setPosition(position.get_x(), position.get_y());
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

void Sprite::sort()
{
	struct
	{
		bool operator()(Node *a, Node *b) const
		{
			auto sprite1 = dynamic_cast<Sprite *>(a);
			auto sprite2 = dynamic_cast<Sprite *>(b);

			if (sprite1 && sprite2)
				return sprite1->get_z() < sprite2->get_z();

			return false;
		}
	} compare_sprites;

	std::sort(_children.begin(), _children.end(), compare_sprites);
}

void Sprite::register_class(lua_State * state)
{
	getGlobalNamespace(state).deriveClass<Sprite, Node2D>("Sprite")
		.addConstructor<void(*) (void), RefCountedPtr<Sprite>>()
		.addProperty("z", &Sprite::get_z, &Sprite::set_z)
		.addProperty("origin", &Sprite::get_origin, &Sprite::set_origin)
		.addFunction("set_texture", &Sprite::set_texture)
		.addFunction("sort", &Sprite::sort)
		.endClass();
}
