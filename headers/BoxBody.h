#pragma once

#include "BodyShape.h"

namespace MakeIt
{
	class BoxBody : public BodyShape
	{
	public:
		BoxBody(float width, float height);

		void create_shape_and_fixture(b2Body *body, b2FixtureDef *fixture) override;

		static void register_class(lua_State *state);

	private:
		float _width, _height;
	};
}