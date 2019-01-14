#include <lua.hpp>
#include <LuaBridge.h>

#include "LuaScript.h"
#include "TextureManager.h"
#include "Sprite.h"

using namespace luabridge;
using namespace MakeIt;

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

void Sprite::set_position(MakeIt::Vector2 vector)
{
	Node2D::set_position(vector);

	sprite.setPosition(position.get_x(), position.get_y());
}

void Sprite::set_scale(MakeIt::Vector2 vector)
{
	Node2D::set_scale(vector);
	sprite.setScale(vector.get_x(), vector.get_y());
}

void Sprite::set_rotate(float angle)
{
	Node2D::set_rotate(angle);
	sprite.setRotation(angle);
}

void Sprite::set_texture(Texture * texture)
{
	sprite.setTexture(*texture->get_texture());
}

void Sprite::open_library(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Sprite>("Sprite")
		.addStaticFunction("create", create)
		.addProperty("position", &Node2D::get_position, &Sprite::set_position)
		.addProperty("scale", &Node2D::get_scale, &Sprite::set_scale)
		.addProperty("rotate", &Node2D::get_rotate, &Sprite::set_rotate)
		.addFunction("set_texture", &Sprite::set_texture)
		.endClass();
}

Sprite *Sprite::create()
{
	auto sprite = new Sprite();
	return sprite;
}

