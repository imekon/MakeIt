#include "Engine.h"
#include "Physics.h"
#include "BoxShape.h"

using namespace luabridge;
using namespace MakeIt;

BoxShape::BoxShape(float width, float height) : _width(width), _height(height)
{

}

void BoxShape::create_shape_and_fixture(b2Body * body, b2FixtureDef *fixture)
{
	auto physics = Physics::get_physics();

	b2PolygonShape shape;
	shape.SetAsBox(_width / physics->get_scaling() / 2.0f, _height / physics->get_scaling() / 2.0f);

	if (fixture)
	{
		fixture->shape = &shape;
		body->CreateFixture(fixture);
	}
	else
		body->CreateFixture(&shape, 0.0f);
}

void BoxShape::register_class(lua_State * state)
{
	getGlobalNamespace(state).deriveClass<BoxShape, BodyShape>("BoxShape")
		.addConstructor<void(*) (float, float), RefCountedPtr<BoxShape>>()
		.endClass();
}

