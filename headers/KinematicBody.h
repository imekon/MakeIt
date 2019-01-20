#pragma once

#include "PhysicsBody.h"

namespace MakeIt
{
	class KinematicBody : public PhysicsBody
	{
	public:
		KinematicBody();

		static void register_class(lua_State *state);
	};
}