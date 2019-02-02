#include <sstream>

#include "Engine.h"
#include "Object.h"

using namespace std;
using namespace MakeIt;

int Object::_name_counter = 0;

Object::Object()
{
	ENGINE_CONSTRUCTOR(this);

	_name_counter++;

	stringstream stream;
	stream << "node" << _name_counter;
	_name = stream.str();
}

Object::~Object()
{
	ENGINE_DESTRUCTOR(this);
}