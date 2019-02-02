#include "Engine.h"

#include <Box2D.h>

#include "StaticBody.h"

using namespace luabridge;
using namespace MakeIt;

StaticBody::StaticBody()
{
	ENGINE_CONSTRUCTOR(this);

	_body_type = b2_staticBody;
}

StaticBody::~StaticBody()
{
	ENGINE_DESTRUCTOR(this);
}

void StaticBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<StaticBody, PhysicsBody>("StaticBody")
		.addConstructor<void(*) (void), RefCountedPtr<StaticBody>>()
		.endClass();
}