#include "Scene.h"

#include <LuaBridge.h>
#include <RefCountedPtr.h>

using namespace luabridge;
using namespace MakeIt;

Scene *Scene::_root = nullptr;

Scene::Scene()
{

}

void Scene::register_class(lua_State *state)
{
	getGlobalNamespace(state).beginClass<Scene>("Scene")
		.addConstructor<void (*)(void), RefCountedPtr<Scene>>()
		.addStaticFunction("get_root", get_root)
		.addStaticFunction("set_root", set_root)
		.addFunction("add_child", &Node::add_child)
		.addFunction("remove_child", &Node::remove_child)
		.endClass();
}