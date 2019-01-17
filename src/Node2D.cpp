#include <lua.hpp>
#include <LuaBridge.h>

#include "LuaScript.h"
#include "Node2D.h"

using namespace luabridge;
using namespace MakeIt;

Node2D::Node2D() : position(0.0f, 0.0f), scale(1.0f, 1.0f), rotate(0.0f)
{

}

Node2D::~Node2D()
{

}

void Node2D::set_position(MakeIt::Vector2 vector)
{
	position = vector;
}

void Node2D::set_scale(MakeIt::Vector2 vector)
{
	scale = vector;
}

void Node2D::set_rotate(float angle)
{
	rotate = angle;
}

void Node2D::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<Node2D, Node>("Node2D")
		.addProperty("position", &Node2D::get_position, &Node2D::set_position)
		.addProperty("scale", &Node2D::get_scale, &Node2D::set_scale)
		.addProperty("rotate", &Node2D::get_rotate, &Node2D::set_rotate)
		.endClass();
}