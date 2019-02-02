#pragma once

#include "PhysicsBody.h"

namespace MakeIt
{
	class DynamicBody : public PhysicsBody
	{
	public:
		DynamicBody();
		virtual ~DynamicBody();

		const char *get_type_name() const override { return "Dynamic"; }
		float get_density() const { return _density; }
		float get_friction() const { return _friction; }
		float get_restitution() const { return _restitution; }
		void set_density(float value);
		void set_friction(float value);
		void set_restitution(float value);

		static void register_class(lua_State *state);

	protected:
		float _density;
		float _friction;
		float _restitution;
		b2FixtureDef fixture;

		b2FixtureDef *get_fixture() override;
	};
}