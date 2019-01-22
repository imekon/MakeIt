#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <Box2D.h>

namespace MakeIt
{
	class BodyShape
	{
	public:
		BodyShape();

		virtual void create_shape_and_fixture(b2Body *body, b2FixtureDef *fixture);

		static void register_class(lua_State *state);
	};
}