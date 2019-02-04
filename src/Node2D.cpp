#include "Engine.h"
#include "LuaScript.h"
#include "Node2D.h"

using namespace luabridge;
using namespace MakeIt;

Node2D::Node2D() : apply_parent_position(true), apply_parent_scale(true), apply_parent_rotate(true),
	_global_position(0.0f, 0.0f), _global_scale(1.0f, 1.0f),  _position(0.0f, 0.0f), _scale(1.0f, 1.0f), _rotate(0.0f)
{
	ENGINE_CONSTRUCTOR(this);
}

Node2D::~Node2D()
{
	ENGINE_DESTRUCTOR(this);
}

void Node2D::set_position(const Vector2 *vector)
{
	_position = *vector;

	for (auto child : _children)
	{
		auto node2d = dynamic_cast<Node2D *>(child);
		if (node2d && node2d->apply_parent_position)
			node2d->set_global_position(vector);
	}
}

void Node2D::set_global_position(const Vector2 *vector)
{
	_global_position = *vector;
}

void MakeIt::Node2D::set_global_scale(const Vector2 *vector)
{
	_global_scale = *vector;
}

void Node2D::set_scale(const Vector2 *vector)
{
	_scale = *vector;

	for (auto child : _children)
	{
		auto node2d = dynamic_cast<Node2D *>(child);
		if (node2d && node2d->apply_parent_scale)
			node2d->set_global_scale(vector);
	}
}

void Node2D::set_rotate(float angle)
{
	_rotate = angle;

	for (auto child : _children)
	{
		auto node2d = dynamic_cast<Node2D *>(child);
		if (node2d)
			node2d->set_rotate(angle);
	}
}

void Node2D::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<Node2D, Node>("Node2D")
		.addConstructor<void (*)(void), RefCountedPtr<Node2D>>()
		.addProperty("type_name", &Node2D::get_type_name)
		.addProperty("global_position", &Node2D::get_global_position, &Node2D::set_global_position)
		.addProperty("position", &Node2D::get_position, &Node2D::set_position)
		.addProperty("scale", &Node2D::get_scale, &Node2D::set_scale)
		.addProperty("rotate", &Node2D::get_rotate, &Node2D::set_rotate)
		.endClass();
}