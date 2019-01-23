#include "CircleShape.h"

using namespace luabridge;
using namespace MakeIt;

CircleShape::CircleShape(float radius) : _radius(radius)
{
}

void CircleShape::create_shape_and_fixture(b2Body * body, b2FixtureDef *fixture)
{
	b2CircleShape shape;
	shape.m_radius = _radius;

	if (fixture)
	{
		fixture->shape = &shape;
		body->CreateFixture(fixture);
	}
	else
		body->CreateFixture(&shape, 0.0f);
}

void MakeIt::CircleShape::register_class(lua_State * state)
{
	getGlobalNamespace(state).deriveClass<CircleShape, BodyShape>("CircleShape")
		.addConstructor<void(*) (float), RefCountedPtr<CircleShape>>()
		.endClass();

}
