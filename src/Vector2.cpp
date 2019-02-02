#include "Engine.h"

#include "Vector2.h"
#include "LuaScript.h"

using namespace luabridge;
using namespace MakeIt;

Vector2::Vector2(float x, float y) : _x(x), _y(y)
{
	ENGINE_CONSTRUCTOR(this);
}

Vector2::~Vector2()
{
	ENGINE_DESTRUCTOR(this);
}

void Vector2::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Vector2>("Vector2")
		.addConstructor<void (*) (float, float), RefCountedPtr<Vector2>>()
		.addProperty("x", &Vector2::get_x, &Vector2::set_x)
		.addProperty("y", &Vector2::get_y, &Vector2::set_y)
		.endClass();
}


