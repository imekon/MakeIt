#include "Engine.h"
#include "Node3D.h"

using namespace MakeIt;

Node3D::Node3D()
{
	ENGINE_CONSTRUCTOR(this);
}

Node3D::~Node3D()
{
	ENGINE_DESTRUCTOR(this);
}