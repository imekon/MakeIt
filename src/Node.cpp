#include "Engine.h"
#include <sstream>

#include "Logger.h"
#include "Node.h"
#include "Physics.h"

using namespace std;
using namespace luabridge;
using namespace MakeIt;

Node::Node() : _visible(true), _z(0)
{
	ENGINE_CONSTRUCTOR(this);
}

Node::~Node()
{
	ENGINE_DESTRUCTOR(this);
}

void Node::add_child(RefCountedPtr<Node> child)
{
	_children.push_back(child);
}

void Node::remove_child(RefCountedPtr<Node> child)
{
	auto iter = find(_children.begin(), _children.end(), child);
	if (iter != _children.end())
		_children.erase(iter);

	//for (auto iter = _children.begin(); iter != _children.end(); ++iter)
	//{
	//	if (iter->get() == child.get())
	//	{
	//		_children.erase(iter);
	//		break;
	//	}
	//}
}

void Node::draw(sf::RenderWindow * window)
{
	if (_visible)
		for (auto child : _children)
			child->draw(window);
}

void Node::update(Physics *physics)
{
	for (auto child : _children)
	{
		child->update(physics);
	}
}

void Node::sort()
{
	struct
	{
		bool operator()(RefCountedPtr<Node> node1, RefCountedPtr<Node> node2) const
		{
			return node1->get_z() < node2->get_z();
		}
	} compare_nodes;

	std::sort(_children.begin(), _children.end(), compare_nodes);
}

void MakeIt::Node::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Node>("Node")
		.addConstructor<void (*)(void), RefCountedPtr<Node>>()
		.addProperty("name", &Node::get_name, &Node::set_name)
		.addProperty("visible", &Node::get_visible, &Node::set_visible)
		.addProperty("z", &Node::get_z, &Node::set_z)
		.addFunction("add_child", &Node::add_child)
		.addFunction("remove_child", &Node::remove_child)
		.addFunction("sort", &Node::sort)
		.endClass();
}
