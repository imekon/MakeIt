#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

namespace MakeIt
{
	class Vector2
	{
	public:
		Vector2(float x, float y);

		float get_x() const { return _x; }
		float get_y() const { return _y; }
		void set_x(float x) { _x = x; }
		void set_y(float y) { _y = y; }

		static void register_class(lua_State *state);

	private:
		float _x, _y;
	};
}