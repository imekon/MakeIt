#include <Box2d.h>

#include "Console.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Scene.h"
#include "Physics.h"
#include "BodyShape.h"
#include "BoxShape.h"
#include "CircleShape.h"
#include "PhysicsBody.h"
#include "StaticBody.h"
#include "KinematicBody.h"
#include "DynamicBody.h"
#include "LuaScript.h"

const int NODE_STORE_MAGIC = 0x4c456761;

using namespace luabridge;
using namespace MakeIt;

Console *LuaScript::console = nullptr;
lua_State *LuaScript::state = nullptr;
bool LuaScript::running = true;

void LuaScript::initialise(Console *cons)
{
	console = cons;
	state = luaL_newstate();
	luaL_openlibs(state);
	register_classes(state);
}

void LuaScript::shutdown()
{
	lua_close(state);
}

bool LuaScript::load_file(const char * filename)
{
	auto result = luaL_loadfile(state, filename);
	if (result != LUA_OK)
	{
		console->print_error(lua_tostring(state, -1));
		return false;
	}

	result = lua_pcall(state, 0, LUA_MULTRET, 0);
	if (result != LUA_OK)
	{
		console->print_error(lua_tostring(state, -1));
		return false;
	}

	return true;
}

bool LuaScript::process(const char *buffer)
{
	int error = luaL_loadbuffer(state, buffer, strlen(buffer), buffer) || lua_pcall(state, 0, 0, 0);
	if (error)
	{
		console->print_error(lua_tostring(state, -1));
		return false;
	}

	return true;
}

bool LuaScript::process_configuration(int &width, int &height, char *title, int length)
{
	lua_getglobal(state, "configuration");
	lua_pushnil(state);
	while (lua_next(state, -2))
	{
		auto key = lua_tostring(state, -2);
		int number = 0;
		const char *text = nullptr;

		if (lua_isnumber(state, -1))
		{
			number = (int)lua_tonumber(state, -1);
		}
		else if (lua_isstring(state, -1))
		{
			text = lua_tostring(state, -1);
		}

		if (strcmp(key, "width") == 0)
			width = number;

		if (strcmp(key, "height") == 0)
			height = number;

		if (strcmp(key, "title") == 0)
			strcpy_s(title, length, text);

		lua_pop(state, 1);
	}

	lua_pop(state, 1);

	return true;
}

bool LuaScript::execute(int args)
{
	lua_pcall(state, args, 0, 0);
	return true;
}

bool LuaScript::execute_function(const char *function_name)
{
	if (!running)
		return false;

	lua_getglobal(state, function_name);
	return execute(0);
}

bool LuaScript::execute_function(const char * function_name, float arg1)
{
	if (!running)
		return false;

	lua_getglobal(state, function_name);
	lua_pushnumber(state, arg1);

	return execute(1);
}

void LuaScript::register_class(lua_State *state)
{
	getGlobalNamespace(state)
		.beginNamespace("System")
		.addFunction("versions", versions)
		.endNamespace();
}

void LuaScript::register_classes(lua_State *state)
{
	register_class(state);
	Node::register_class(state);
	Node2D::register_class(state);
	Vector2::register_class(state);
	Texture::register_class(state);
	Sprite::register_class(state);
	Scene::register_class(state);
	Physics::register_class(state);
	BodyShape::register_class(state);
	BoxShape::register_class(state);
	CircleShape::register_class(state);
	PhysicsBody::register_class(state);
	StaticBody::register_class(state);
	KinematicBody::register_class(state);
	DynamicBody::register_class(state);
	Console::register_class(state);
}

void LuaScript::create_texture_store(lua_State * state, sf::Texture * texture)
{
	GenericDataStore *node_store = static_cast<GenericDataStore *>(lua_newuserdata(state, sizeof(GenericDataStore)));

	node_store->magic = NODE_STORE_MAGIC;
	node_store->type = DATA::TEXTURE;
	node_store->data = texture;
}

void LuaScript::create_vector_store(lua_State * state, MakeIt::Vector2 * vector)
{
	GenericDataStore *node_store = static_cast<GenericDataStore *>(lua_newuserdata(state, sizeof(GenericDataStore)));

	node_store->magic = NODE_STORE_MAGIC;
	node_store->type = DATA::VECTOR;
	node_store->data = vector;
}

void LuaScript::create_node_store(lua_State * state, MakeIt::Node * node)
{
	GenericDataStore *node_store = static_cast<GenericDataStore *>(lua_newuserdata(state, sizeof(GenericDataStore)));

	node_store->magic = NODE_STORE_MAGIC;
	node_store->type = DATA::NODE;
	node_store->data = node;
}

void LuaScript::versions()
{
	console->print("MakeIt Game Engine V0.2 (c) 2019 Pete Goodwin\n");
	console->print("ImGui version: %s\n", ImGui::GetVersion());
	console->print("Box2D version: %d.%d.%d\n", b2_version.major, b2_version.minor, b2_version.revision);
	console->print("Lua version %s.%s.%s\n", LUA_VERSION_MAJOR, LUA_VERSION_MINOR, LUA_VERSION_RELEASE);
	console->print("LuaBridge version %d.%d\n", LUABRIDGE_MAJOR_VERSION, LUABRIDGE_MAJOR_VERSION);
}
