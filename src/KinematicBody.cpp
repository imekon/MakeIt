#include <Box2D.h>

#include "KinematicBody.h"

using namespace luabridge;
using namespace MakeIt;

KinematicBody::KinematicBody()
{
	_body_type = b2_kinematicBody;
}

void KinematicBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<KinematicBody, PhysicsBody>("KinematicBody")
		.addConstructor<void(*) (void), RefCountedPtr<KinematicBody>>()
		.endClass();
}