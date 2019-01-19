#pragma once

#include <vector>
#include <box2d/Box2D.h>
#include "Node.h"

namespace MakeIt
{
	class Physics : public Node
	{
	public:
		Physics(float gravityFactor, float scaling);

		bool get_enabled() const { return enabled; }
		float get_scaling() const { return scaling; }

		void set_enabled(bool value) { enabled = value; }
		void set_scaling(float value);

		void step();
		b2World *getWorld() { return &world; }

		static void register_class(lua_State *state);

		static Physics *get_physics() { return _physics; }
		static void set_physics(Physics *physics) { _physics = physics; }

	private:
		bool enabled;
		float scaling;
		b2Vec2 gravity;
		b2World world;

		static Physics *_physics;
	};
}