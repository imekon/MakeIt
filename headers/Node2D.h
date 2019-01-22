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

		virtual void set_position(Vector2 vector);
		void set_position(float x, float y) { set_position(Vector2(x, y)); }
		virtual void set_global_position(Vector2 vector);
		virtual void set_scale(MakeIt::Vector2 vector);
		virtual void set_rotate(float angle);

		Vector2 get_position() const { return _position; }
		Vector2 get_global_position() const { return _global_position; }
		Vector2 get_scale() const { return _scale; }
		float get_rotate() const { return _rotate; }

		static void register_class(lua_State *state);

	protected:
		Vector2 _position;
		Vector2 _global_position;
		Vector2 _scale;
		float _rotate;
	};
}
