#include "Engine.h"

#include "Scene.h"

using namespace luabridge;
using namespace MakeIt;

Scene *Scene::_root = nullptr;

Scene::Scene()
{
	ENGINE_CONSTRUCTOR(this);
}

Scene::~Scene()
{
	ENGINE_DESTRUCTOR(this);
}

void Scene::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<Scene, Node>("Scene")
		.addConstructor<void (*)(void), RefCountedPtr<Scene>>()
		.addStaticFunction("get_root", get_root)
		.addStaticFunction("set_root", set_root)
		.endClass();
}