#include <Box2D.h>

#include "StaticBody.h"

using namespace luabridge;
using namespace MakeIt;

StaticBody::StaticBody()
{
	_body_type = b2_staticBody;
}

void StaticBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<StaticBody, PhysicsBody>("StaticBody")
		.addConstructor<void(*) (void), RefCountedPtr<StaticBody>>()
		.endClass();
}