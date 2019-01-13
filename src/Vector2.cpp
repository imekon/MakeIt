#include <lua.hpp>

#include "Vector2.h"
#include "LuaScript.h"

using namespace MakeIt;

luaL_Reg Vector2::library[] =
{
	"create",	Vector2::create_feature,
	"set",		Vector2::set_feature,
	"get",		Vector2::get_feature,

	nullptr, nullptr
};

Vector2::Vector2(float x, float y) : x(x), y(y)
{

}

void MakeIt::Vector2::set(float _x, float _y)
{
	x = _x;
	y = _y;
}

int Vector2::open_library(lua_State * state)
{
	luaL_newlib(state, library);
	return 1;
}

int Vector2::create_feature(lua_State * state)
{
	float x = (float)lua_tonumber(state, 1);
	float y = (float)lua_tonumber(state, 2);
	auto vector = new Vector2(x, y);
	LuaScript::create_vector_store(state, vector);
	return 1;
}

int Vector2::get_feature(lua_State * state)
{
	auto data_store = static_cast<GenericDataStore *>(lua_touserdata(state, 1));

	if (data_store)
	{
		float x = static_cast<Vector2 *>(data_store->data)->get_x();
		float y = static_cast<Vector2 *>(data_store->data)->get_y();

		lua_pushnumber(state, x);
		lua_pushnumber(state, y);

		return 2;
	}

	return 0;
}

int Vector2::set_feature(lua_State * state)
{
	auto data_store = static_cast<GenericDataStore *>(lua_touserdata(state, 1));

	if (data_store)
	{
		float x = (float)lua_tonumber(state, 2);
		float y = (float)lua_tonumber(state, 3);

		auto vector = static_cast<Vector2 *>(data_store->data);
		vector->set(x, y);
	}

	return 0;
}
