#include "CircleBody.h"

using namespace luabridge;
using namespace MakeIt;

CircleBody::CircleBody(float radius) : _radius(radius)
{
}

void CircleBody::create_shape_and_fixture(b2Body * body, b2FixtureDef *fixture)
{
	b2CircleShape shape;
	shape.m_radius = _radius;

	if (fixture)
	{
		fixture->shape = &shape;
		fixture->density = 1.0f;
		fixture->friction = 0.0f;
		body->CreateFixture(fixture);
	}
	else
		body->CreateFixture(&shape, 0.0f);
}

void MakeIt::CircleBody::register_class(lua_State * state)
{
	getGlobalNamespace(state).deriveClass<CircleBody, BodyShape>("CircleBody")
		.addConstructor<void(*) (float), RefCountedPtr<CircleBody>>()
		.endClass();

}
