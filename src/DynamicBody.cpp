#include "Engine.h"
#include <Box2D.h>

#include "DynamicBody.h"

using namespace luabridge;
using namespace MakeIt;

DynamicBody::DynamicBody() : _density(1.0f), _friction(0.0f), _restitution(0.0f)
{
	_body_type = b2_dynamicBody;
}

void MakeIt::DynamicBody::set_density(float value)
{
	_density = value;
}

void MakeIt::DynamicBody::set_friction(float value)
{
	_friction = value;
}

void MakeIt::DynamicBody::set_restitution(float value)
{
	_restitution = value;
}

void DynamicBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<DynamicBody, PhysicsBody>("DynamicBody")
		.addConstructor<void(*) (void), RefCountedPtr<DynamicBody>>()
		.addProperty("density", &DynamicBody::get_density, &DynamicBody::set_density)
		.addProperty("friction", &DynamicBody::get_friction, &DynamicBody::set_friction)
		.addProperty("restitution", &DynamicBody::get_restitution, &DynamicBody::set_restitution)
		.endClass();
}

b2FixtureDef * DynamicBody::get_fixture()
{
	fixture.density = _density;
	fixture.friction = _friction;
	fixture.restitution = _restitution;

	return &fixture;
}
