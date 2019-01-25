#pragma once

#include "Node2D.h"

namespace MakeIt
{
	class Physics;
	class BodyShape;

	class PhysicsBody : public Node2D
	{
	public:
		PhysicsBody();

		virtual void set_shape(BodyShape *shape);
		void set_position(Vector2 vector) override;
		void update(Physics *physics) override;

		static void register_class(lua_State *state);

	protected:
		b2BodyType _body_type;
		b2Body *body;

		virtual b2FixtureDef *get_fixture();
		void set_physics_position(float x, float y, bool update_physics) override;
	};
}