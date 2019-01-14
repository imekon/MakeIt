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

		virtual void set_position(MakeIt::Vector2 vector);
		virtual void set_scale(MakeIt::Vector2 vector);
		virtual void set_rotate(float angle);

		Vector2 get_position() const { return position; }
		Vector2 get_scale() const { return scale; }
		float get_rotate() const { return rotate; }

	protected:
		Vector2 position;
		Vector2 scale;
		float rotate;
	};
}
