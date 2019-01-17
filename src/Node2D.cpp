#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include "LuaScript.h"
#include "Node2D.h"

using namespace luabridge;
using namespace MakeIt;

Node2D::Node2D() : _global_position(0.0f, 0.0f), _position(0.0f, 0.0f), _scale(1.0f, 1.0f), _rotate(0.0f)
{

}

Node2D::~Node2D()
{

}

void Node2D::set_position(Vector2 vector)
{
	_position = vector;

	for (auto child : _children)
	{
		auto node2d = dynamic_cast<Node2D *>(child);
		if (node2d)
			node2d->set_global_position(vector);
	}
}

void Node2D::set_global_position(Vector2 vector)
{
	_global_position = vector;
}

void Node2D::set_scale(MakeIt::Vector2 vector)
{
	_scale = vector;
}

void Node2D::set_rotate(float angle)
{
	_rotate = angle;
}

void Node2D::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<Node2D, Node>("Node2D")
		.addConstructor<void (*)(void), RefCountedPtr<Node2D>>()
		.addProperty("global_position", &Node2D::get_global_position, &Node2D::set_global_position)
		.addProperty("position", &Node2D::get_position, &Node2D::set_position)
		.addProperty("scale", &Node2D::get_scale, &Node2D::set_scale)
		.addProperty("rotate", &Node2D::get_rotate, &Node2D::set_rotate)
		.endClass();
}