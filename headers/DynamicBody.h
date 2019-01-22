#pragma once

#include "PhysicsBody.h"

namespace MakeIt
{
	class DynamicBody : public PhysicsBody
	{
	public:
		DynamicBody();

		static void register_class(lua_State *state);

	protected:
		b2FixtureDef fixture;

		b2FixtureDef *get_fixture() override;
	};
}