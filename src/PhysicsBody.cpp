#define _USE_MATH_DEFINES
#include <math.h>

#include <Box2D.h>

#include "Physics.h"
#include "BodyShape.h"
#include "PhysicsBody.h"

using namespace luabridge;
using namespace MakeIt;

#define R2D(angle) (angle) * 360.0f / 2.0f / (float)M_PI

PhysicsBody::PhysicsBody()
{

}

void PhysicsBody::set_shape(Physics *physics, BodyShape *shape)
{
	auto x = _position.get_x() / physics->get_scaling();
	auto y = _position.get_y() / physics->get_scaling();

	b2BodyDef body_def;
	body_def.position.Set(x, y);
	body_def.type = _body_type;
	body = physics->getWorld()->CreateBody(&body_def);

	shape->create_shape_and_fixture(body, get_fixture());
}

void PhysicsBody::update(Physics *physics)
{
	Node2D::update(physics);

	auto pos = body->GetPosition();
	set_position(pos.x * physics->get_scaling(), pos.y * physics->get_scaling());
	auto angle = body->GetAngle();
	set_rotate(R2D(angle));
}

void PhysicsBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<PhysicsBody, Node2D>("PhysicsBody")
		.addConstructor<void(*) (void), RefCountedPtr<PhysicsBody>>()
		.addFunction("set_shape", &PhysicsBody::set_shape)
		.endClass();
}

b2FixtureDef *PhysicsBody::get_fixture()
{
	return nullptr;
}
