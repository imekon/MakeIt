#define _USE_MATH_DEFINES
#include <math.h>

#include <Box2D.h>

//#include <spdlog/spdlog.h>

#include "Physics.h"
#include "BodyShape.h"
#include "PhysicsBody.h"

using namespace luabridge;
using namespace MakeIt;

#define R2D(angle) (angle) * 360.0f / 2.0f / (float)M_PI

PhysicsBody::PhysicsBody() : update_physics(false)
{

}

void PhysicsBody::set_shape(BodyShape *shape)
{
	auto physics = Physics::get_physics();

	if (physics == nullptr)
		return;

	auto x = _position.get_x() / physics->get_scaling();
	auto y = _position.get_y() / physics->get_scaling();

	b2BodyDef body_def;
	body_def.position.Set(x, y);
	body_def.type = _body_type;
	body = physics->getWorld()->CreateBody(&body_def);

	shape->create_shape_and_fixture(body, get_fixture());
}

void PhysicsBody::set_position(Vector2 vector)
{
	update_physics = true;
	Node2D::set_position(vector);
}

void PhysicsBody::update(Physics *physics)
{
	Node2D::update(physics);

	if (update_physics)
	{
		auto physics = Physics::get_physics();
		if (physics && body)
			body->SetTransform(b2Vec2(_position.get_x() / physics->get_scaling(), _position.get_y() / physics->get_scaling()), _rotate);

		update_physics = false;
	}
	else
	{
		auto pos = body->GetPosition();
		Node2D::set_position(Vector2(pos.x * physics->get_scaling(), pos.y * physics->get_scaling()));
		auto angle = body->GetAngle();
		set_rotate(R2D(angle));
	}
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
