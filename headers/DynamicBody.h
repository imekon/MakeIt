#pragma once

#include "PhysicsBody.h"

namespace MakeIt
{
	class DynamicBody : public PhysicsBody
	{
	public:
		DynamicBody();

		static void register_class(lua_State *state);
	};
}