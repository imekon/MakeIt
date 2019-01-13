#pragma once

#include <vector>

namespace MakeIt
{
	class Node
	{
	public:
		Node();
		virtual ~Node();

		virtual void add_child(Node *child);
		virtual void remove_child(Node *child);

	protected:
		std::vector<Node *> children;
	};
}
