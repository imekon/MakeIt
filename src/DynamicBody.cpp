#include <Box2D.h>

#include "DynamicBody.h"

using namespace luabridge;
using namespace MakeIt;

DynamicBody::DynamicBody()
{
	_body_type = b2_dynamicBody;
}

void DynamicBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<DynamicBody, PhysicsBody>("DynamicBody")
		.addConstructor<void(*) (void), RefCountedPtr<DynamicBody>>()
		.endClass();
}

b2FixtureDef * MakeIt::DynamicBody::get_fixture()
{
	fixture.density = 1.0f;
	fixture.friction = 0.0f;

	return &fixture;
}
