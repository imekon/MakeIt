#include "LuaScript.h"
#include "Sprite.h"

using namespace MakeIt;

luaL_Reg Sprite::library[] =
{
	"create",			Sprite::create_feature,
	"set_translate",	Node2D::set_translate_feature,
	"set_scale",		Node2D::set_scale_feature,
	"set_rotate",		Node2D::set_rotate_feature,

	nullptr, nullptr
};

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

void Sprite::set_translate(MakeIt::Vector2 vector)
{
	Node2D::set_translate(vector);

	sprite.setPosition(translate.get_x(), translate.get_y());
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

void Sprite::set_texture(sf::Texture * texture)
{
	sprite.setTexture(*texture);
}

int Sprite::open_library(lua_State * state)
{
	luaL_newlib(state, library);
	return 1;
}

int Sprite::create_feature(lua_State * state)
{
	auto sprite = new Sprite();
	LuaScript::create_node_store(state, sprite);
	return 1;
}

