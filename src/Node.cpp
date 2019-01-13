#include "Node.h"

using namespace std;
using namespace MakeIt;

Node::Node()
{

}

Node::~Node()
{

}

void MakeIt::Node::add_child(Node * child)
{
	children.push_back(child);
}

void MakeIt::Node::remove_child(Node * child)
{

}
