#pragma once

#include "PhysicsBody.h"

namespace MakeIt
{
	class KinematicBody : public PhysicsBody
	{
	public:
		KinematicBody();

		const char *get_type_name() const override { return "Kinematic"; }

		static void register_class(lua_State *state);
	};
}