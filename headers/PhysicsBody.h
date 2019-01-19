#pragma once

#include "Node2D.h"

namespace MakeIt
{
	class Physics;

	class PhysicsBody : public Node2D
	{
	public:
		PhysicsBody();

		void update(Physics *physics) override;
	};
}