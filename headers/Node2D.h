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

		const char *get_type_name() const override { return "Node2D"; }
		virtual void set_position(const Vector2 *vector);
		virtual void set_position(float x, float y) { set_position(new Vector2(x, y)); }
		virtual void set_scale(const Vector2 *vector);
		virtual void set_rotate(float angle);
		virtual void set_global_position(const Vector2 *vector);
		virtual void set_global_scale(const Vector2 *vector);

		const Vector2 *get_position() const { return &_position; }
		const Vector2 *get_scale() const { return &_scale; }
		float get_rotate() const { return _rotate; }
		const Vector2 *get_global_position() const { return &_global_position; }
		const Vector2 *get_global_scale() const { return &_global_scale; }

		static void register_class(lua_State *state);

	protected:
		bool apply_parent_position : 1;
		bool apply_parent_scale : 1;
		bool apply_parent_rotate : 1;

		Vector2 _position;
		Vector2 _scale;
		float _rotate;
		Vector2 _global_position;
		Vector2 _global_scale;
	};
}
