#include "LuaScript.h"
#include "Node2D.h"

using namespace MakeIt;

Node2D::Node2D() : translate(0.0f, 0.0f), scale(1.0f, 1.0f), rotate(0.0f)
{

}

Node2D::~Node2D()
{

}

void Node2D::set_translate(MakeIt::Vector2 vector)
{
	translate = vector;
}

void Node2D::set_scale(MakeIt::Vector2 vector)
{
	scale = vector;
}

void Node2D::set_rotate(float angle)
{
	rotate = angle;
}

int Node2D::set_translate_feature(lua_State * state)
{
	auto data_store = static_cast<GenericDataStore *>(lua_touserdata(state, 1));

	if (data_store)
	{
		auto x = (float)lua_tonumber(state, 2);
		auto y = (float)lua_tonumber(state, 3);
		static_cast<Node2D *>(data_store->data)->set_translate(Vector2(x, y));
	}

	return 0;
}

int Node2D::set_scale_feature(lua_State * state)
{
	auto data_store = static_cast<GenericDataStore *>(lua_touserdata(state, 1));

	if (data_store)
	{
		auto x = (float)lua_tonumber(state, 2);
		auto y = (float)lua_tonumber(state, 3);
		static_cast<Node2D *>(data_store->data)->set_scale(Vector2(x, y));
	}

	return 0;
}

int Node2D::set_rotate_feature(lua_State * state)
{
	auto data_store = static_cast<GenericDataStore *>(lua_touserdata(state, 1));

	if (data_store)
	{
		auto angle = (float)lua_tonumber(state, 2);
		static_cast<Node2D *>(data_store->data)->set_rotate(angle);
	}

	return 0;
}
