#include "Physics.h"
#include "PhysicsBody.h"

using namespace MakeIt;

PhysicsBody::PhysicsBody()
{

}

void PhysicsBody::update(Physics *physics)
{
	Node2D::update(physics);
}