#include "Node.h"

#include <LuaBridge.h>
#include <RefCountedPtr.h>

using namespace std;
using namespace luabridge;
using namespace MakeIt;

Node::Node() : _visible(true), _z(0)
{

}

Node::~Node()
{

}

void Node::add_child(Node * child)
{
	_children.push_back(child);
}

void Node::remove_child(Node * child)
{
	auto iter = find(_children.begin(), _children.end(), child);
	if (iter != _children.end())
		_children.erase(iter);
}

void Node::draw(sf::RenderWindow * window)
{
	if (_visible)
		for (auto child : _children)
			child->draw(window);
}

void Node::sort()
{
	struct
	{
		bool operator()(Node *node1, Node *node2) const
		{
			return node1->get_z() < node2->get_z();
		}
	} compare_sprites;

	std::sort(_children.begin(), _children.end(), compare_sprites);
}


void MakeIt::Node::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Node>("Node")
		.addConstructor<void (*)(void), RefCountedPtr<Node>>()
		.addProperty("visible", &Node::get_visible, &Node::set_visible)
		.addProperty("z", &Node::get_z, &Node::set_z)
		.addFunction("add_child", &Node::add_child)
		.addFunction("remove_child", &Node::remove_child)
		.addFunction("sort", &Node::sort)
		.endClass();
}
