#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <Box2D.h>

#include "Object.h"

namespace MakeIt
{
	class BodyShape : public Object
	{
	public:
		BodyShape();
		virtual ~BodyShape();

		const char * get_type_name() const override { return "BodyShape"; }

		virtual void create_shape_and_fixture(b2Body *body, b2FixtureDef *fixture);

		static void register_class(lua_State *state);
	};
}