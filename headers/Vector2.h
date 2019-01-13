#pragma once

#include <lua.hpp>

namespace MakeIt
{
	class Vector2
	{
	public:
		Vector2(float x, float y);

		float get_x() const { return x; }
		float get_y() const { return y; }

		void set(float _x, float _y);

		static int open_library(lua_State *state);

	private:
		float x, y;

		static luaL_Reg library[];

		static int create_feature(lua_State *state);
		static int get_feature(lua_State *state);
		static int set_feature(lua_State *state);
	};
}