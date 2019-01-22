#include "BoxBody.h"

using namespace luabridge;
using namespace MakeIt;

BoxBody::BoxBody(float width, float height) : _width(width), _height(height)
{

}

void BoxBody::create_shape_and_fixture(b2Body * body, b2FixtureDef *fixture)
{
	b2PolygonShape shape;
	shape.SetAsBox(_width, _height);

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

void BoxBody::register_class(lua_State * state)
{
	getGlobalNamespace(state).deriveClass<BoxBody, BodyShape>("BoxBody")
		.addConstructor<void(*) (float, float), RefCountedPtr<BoxBody>>()
		.endClass();
}

