#pragma once

#include <vector>
#include <box2d/Box2D.h>
#include "Node.h"

namespace MakeIt
{
	class PhysicsDebug;

	class Physics : public Node
	{
	public:
		Physics(float gravityFactor, float scaling);

		const char *get_type_name() const override { return "Physics"; }

		bool get_enabled() const { return enabled; }
		bool get_debug() const { return debug; }
		float get_scaling() const { return scaling; }

		void set_enabled(bool value) { enabled = value; }
		void set_debug(bool value) { debug = value; }
		void set_scaling(float value);

		void set_debug_draw(PhysicsDebug *debug_draw);

		void step();
		b2World *get_world() { return &world; }

		static void register_class(lua_State *state);

		static Physics *get_physics() { return _physics; }

	private:
		bool enabled;
		bool debug;
		float scaling;
		b2Vec2 gravity;
		b2World world;

		static Physics *_physics;
	};
}