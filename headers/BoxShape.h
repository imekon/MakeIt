#pragma once

#include "BodyShape.h"

namespace MakeIt
{
	class BoxShape : public BodyShape
	{
	public:
		BoxShape(float width, float height);
		virtual ~BoxShape();

		const char * get_type_name() const override { return "BoxShape"; }

		void create_shape_and_fixture(b2Body *body, b2FixtureDef *fixture) override;

		static void register_class(lua_State *state);

	private:
		float _width, _height;
	};
}