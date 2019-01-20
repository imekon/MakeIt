#include <Box2D.h>

#include "Physics.h"
#include "BodyShape.h"
#include "PhysicsBody.h"

using namespace luabridge;
using namespace MakeIt;

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

	shape->createShapeAndFixture(body);
}

void PhysicsBody::update(Physics *physics)
{
	Node2D::update(physics);
}

void PhysicsBody::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<PhysicsBody, Node2D>("PhysicsBody")
		.addConstructor<void(*) (void), RefCountedPtr<PhysicsBody>>()
		.endClass();
}