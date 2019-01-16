#include <algorithm>

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include "LuaScript.h"
#include "TextureManager.h"
#include "Sprite.h"

using namespace luabridge;
using namespace MakeIt;

SpriteManager *SpriteManager::instance = nullptr;

Sprite::Sprite() : _origin(0.0f, 0.0f), _z(0), _visible(true)
{
	SpriteManager::getInstance()->add_sprite(this);
}

Sprite::~Sprite()
{
	SpriteManager::getInstance()->remove_sprite(this);
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
	window->draw(_sprite);
}

void Sprite::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Sprite>("Sprite")
		.addConstructor<void(*) (void), RefCountedPtr<Sprite>>()
		.addProperty("position", &Node2D::get_position, &Sprite::set_position)
		.addProperty("scale", &Node2D::get_scale, &Sprite::set_scale)
		.addProperty("rotate", &Node2D::get_rotate, &Sprite::set_rotate)
		.addProperty("z", &Sprite::get_z, &Sprite::set_z)
		.addProperty("origin", &Sprite::get_origin, &Sprite::set_origin)
		.addProperty("visible", &Sprite::get_visible, &Sprite::set_visible)
		.addFunction("set_texture", &Sprite::set_texture)
		.addStaticFunction("sort", &SpriteManager::sort)
		.endClass();
}

SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{
}

void SpriteManager::add_sprite(Sprite *sprite)
{
	sprites.push_back(sprite);
}

void SpriteManager::remove_sprite(Sprite *sprite)
{
	auto iter = find(sprites.begin(), sprites.end(), sprite);
	if (iter != sprites.end())
		sprites.erase(iter);
}

void SpriteManager::draw(sf::RenderWindow *window)
{
	for (auto sprite : sprites)
	{
		if (sprite->get_visible())
			sprite->draw(window);
	}
}

void SpriteManager::sort()
{
	struct
	{
		bool operator()(Sprite *a, Sprite *b) const
		{
			return a->get_z() < b->get_z();
		}
	} compare_sprites;

	std::sort(instance->sprites.begin(), instance->sprites.end(), compare_sprites);
}

SpriteManager *SpriteManager::getInstance()
{
	if (instance == nullptr)
		instance = new SpriteManager();

	return instance;
}

void SpriteManager::shutdown()
{
	if (instance)
		delete instance;

	instance = nullptr;
}