#pragma once

#include "PhysicsBody.h"

namespace MakeIt
{
	class StaticBody : public PhysicsBody
	{
	public:
		StaticBody();
		virtual ~StaticBody();

		const char *get_type_name() const override { return "Static"; }

		static void register_class(lua_State *state);
	};
}
