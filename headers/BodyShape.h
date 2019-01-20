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

		void createShapeAndFixture(b2Body *body);

		static void register_class(lua_State *state);
	};
}