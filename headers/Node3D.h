#pragma once

#include "Node.h"

namespace MakeIt
{
	class Node3D : public Node
	{
	public:
		Node3D();
		virtual ~Node3D();

		const char *get_type_name() const override { return "Node3D"; }
	};
}
