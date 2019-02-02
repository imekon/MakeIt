#pragma once

#include "BodyShape.h"

namespace MakeIt
{
	class CircleShape : public BodyShape
	{
	public:
		CircleShape(float radius);
		virtual ~CircleShape();

		void create_shape_and_fixture(b2Body *body, b2FixtureDef *fixture) override;

		static void register_class(lua_State *state);

	private:
		float _radius;
	};
}