#include "Sprite.h"

using namespace MakeIt;

luaL_Reg Sprite::library[] =
{
	"set_translate",	Sprite::set_translate_feature,
	"set_scale",		Sprite::set_scale_feature,
	"set_rotate",		Sprite::set_rotate_feature,

	nullptr, nullptr
};



Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

void MakeIt::Sprite::set_translate(MakeIt::Vector2 vector)
{
	Node2D::set_translate(vector);

	sprite.setPosition(translate.get_x(), translate.get_y());
}

void MakeIt::Sprite::set_scale(MakeIt::Vector2 vector)
{
	Node2D::set_scale(vector);
	sprite.setScale(vector.get_x(), vector.get_y());
}

void MakeIt::Sprite::set_rotate(float angle)
{
	Node2D::set_rotate(angle);
	sprite.setRotation(angle);
}

void MakeIt::Sprite::set_texture(sf::Texture * texture)
{
	sprite.setTexture(*texture);
}

int Sprite::open_library(lua_State * state)
{
	return 0;
}

int Sprite::set_translate_feature(lua_State * state)
{
	return 0;
}

int Sprite::set_scale_feature(lua_State * state)
{
	return 0;
}

int Sprite::set_rotate_feature(lua_State * state)
{
	return 0;
}
