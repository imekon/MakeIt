#include "Engine.h"
#include <Box2D.h>

#include "KinematicBody.h"

using namespace luabridge;
using namespace MakeIt;

KinematicBody::KinematicBody()
{
	ENGINE_CONSTRUCTOR(this);

	_body_type = b2_kinematicBody;
}

KinematicBody::~KinematicBody()
{
	ENGINE_DESTRUCTOR(this);
}

void KinematicBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<KinematicBody, PhysicsBody>("KinematicBody")
		.addConstructor<void(*) (void), RefCountedPtr<KinematicBody>>()
		.endClass();
}