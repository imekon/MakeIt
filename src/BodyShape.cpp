#include "BodyShape.h"

using namespace luabridge;
using namespace MakeIt;

BodyShape::BodyShape()
{

}

void BodyShape::createShapeAndFixture(b2Body *body)
{

}

void BodyShape::register_class(lua_State *state)
{
	getGlobalNamespace(state).beginClass<BodyShape>("BodyShape")
		.addConstructor<void(*) (void), RefCountedPtr<BodyShape>>()
		.endClass();
}