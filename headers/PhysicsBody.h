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

		virtual void set_shape(Physics *physics, BodyShape *shape);
		void update(Physics *physics) override;

		static void register_class(lua_State *state);

	protected:
		b2BodyType _body_type;
		b2Body *body;
	};
}