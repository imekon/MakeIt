#include "Engine.h"
#include "Physics.h"
#include "CircleShape.h"

using namespace luabridge;
using namespace MakeIt;

CircleShape::CircleShape(float radius) : _radius(radius)
{
	ENGINE_CONSTRUCTOR(this);
}

CircleShape::~CircleShape()
{
	ENGINE_DESTRUCTOR(this);
}

void CircleShape::create_shape_and_fixture(b2Body * body, b2FixtureDef *fixture)
{
	auto physics = Physics::get_physics();

	b2CircleShape shape;
	shape.m_radius = _radius / physics->get_scaling();

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
