#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include "Object.h"

namespace MakeIt
{
	class Vector2 : public Object
	{
	public:
		Vector2(float x, float y);
		virtual ~Vector2();

		const char * get_type_name() const override { return "Vector2"; }
		float get_x() const { return _x; }
		float get_y() const { return _y; }
		void set_x(float x) { _x = x; }
		void set_y(float y) { _y = y; }

		static float dot(const Vector2 *first, const Vector2 *second);

		static void register_class(lua_State *state);

	private:
		float _x, _y;
	};
}