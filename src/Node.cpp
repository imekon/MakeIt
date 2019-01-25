#include <sstream>

#include "Node.h"
#include "Physics.h"

using namespace std;
using namespace luabridge;
using namespace MakeIt;

int Node::_name_counter = 0;

Node::Node() : _visible(true), _z(0)
{
	_name_counter++;
	
	stringstream stream;
	stream << "node" << _name_counter;
	_name = stream.str();
}

Node::~Node()
{

}

void Node::add_child(Node * child)
{
	if (child)
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
			if (child)
				child->draw(window);
}

void Node::update(Physics *physics)
{
	for (auto child : _children)
	{
		if (child)
			child->update(physics);
	}
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
		.addProperty("name", &Node::get_name, &Node::set_name)
		.addProperty("visible", &Node::get_visible, &Node::set_visible)
		.addProperty("z", &Node::get_z, &Node::set_z)
		.addFunction("add_child", &Node::add_child)
		.addFunction("remove_child", &Node::remove_child)
		.addFunction("sort", &Node::sort)
		.endClass();
}
