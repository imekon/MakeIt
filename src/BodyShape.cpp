#include "Engine.h"
#include "BodyShape.h"

using namespace luabridge;
using namespace MakeIt;

BodyShape::BodyShape()
{

}

void BodyShape::create_shape_and_fixture(b2Body *body, b2FixtureDef *fixture)
{

}

void BodyShape::register_class(lua_State *state)
{
	getGlobalNamespace(state).beginClass<BodyShape>("BodyShape")
		.addConstructor<void(*) (void), RefCountedPtr<BodyShape>>()
		.endClass();
}