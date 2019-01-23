#include "BoxShape.h"

using namespace luabridge;
using namespace MakeIt;

BoxShape::BoxShape(float width, float height) : _width(width), _height(height)
{

}

void BoxShape::create_shape_and_fixture(b2Body * body, b2FixtureDef *fixture)
{
	b2PolygonShape shape;
	shape.SetAsBox(_width, _height);

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

