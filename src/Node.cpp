#include "Node.h"

#include <LuaBridge.h>
#include <RefCountedPtr.h>

using namespace std;
using namespace luabridge;
using namespace MakeIt;

Node::Node() : _visible(true)
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

void MakeIt::Node::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Node>("Node")
		.addConstructor<void (*)(void), RefCountedPtr<Node>>()
		.addProperty("visible", &Node::get_visible, &Node::set_visible)
		.addFunction("add_child", &Node::add_child)
		.addFunction("remove_child", &Node::remove_child)
		.endClass();
}
