#pragma once

#include "PhysicsBody.h"

namespace MakeIt
{
	class StaticBody : public PhysicsBody
	{
	public:
		StaticBody();

		static void register_class(lua_State *state);
	};
}
