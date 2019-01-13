#pragma once

#include "Vector2.h"
#include "Node.h"

namespace MakeIt
{
	class Node2D : public Node
	{
	public:
		Node2D();
		virtual ~Node2D();

		virtual void set_translate(MakeIt::Vector2 vector);
		virtual void set_scale(MakeIt::Vector2 vector);
		virtual void set_rotate(float angle);

		Vector2 get_translate() const { return translate; }
		Vector2 get_scale() const { return scale; }
		float get_rotate() const { return rotate; }

	protected:
		Vector2 translate;
		Vector2 scale;
		float rotate;

		static int set_translate_feature(lua_State *state);
		static int set_scale_feature(lua_State *state);
		static int set_rotate_feature(lua_State *state);
	};
}
