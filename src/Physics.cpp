#include "Physics.h"

using namespace luabridge;
using namespace MakeIt;

Physics *Physics::_physics = nullptr;

Physics::Physics(float gravityFactor, float scaling)
	: gravity(0.0f, gravityFactor), world(gravity), scaling(scaling), enabled(true)
{

}

void Physics::set_scaling(float value)
{
	scaling = value;
}

void Physics::step()
{
	if (enabled)
	{
		auto timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;

		world.Step(timeStep, velocityIterations, positionIterations);
	}
}

void Physics::register_class(lua_State * state)
{
	getGlobalNamespace(state).deriveClass<Physics, Node>("Physics")
		.addConstructor<void(*) (float, float), RefCountedPtr<Physics>>()
		.addProperty("enabled", &Physics::get_enabled, &Physics::set_enabled)
		.addProperty("scaling", &Physics::get_scaling, &Physics::set_scaling)
		.addStaticFunction("get_physics", get_physics)
		.addStaticFunction("set_physics", set_physics)
		.endClass();
}

