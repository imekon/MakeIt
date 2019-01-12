#pragma once

#include <lua.hpp>

#include "Node.h"

class Console;

struct NodeStore
{
	int magic;
	MakeIt::Node *node;
};

class LuaScript
{
public:
	static void initialise(Console *cons);
	static void shutdown();

	static bool load_file(const char *filename);
	static bool process(const char *buffer);
	static bool process_configuration(int &width, int &height, char *title, int length);

private:
	static Console *console;
	static lua_State *state;

	static luaL_Reg library[];
	static luaL_Reg libraries[];

	static void print_error(lua_State *state);
	static int open_library(lua_State *state);
	static void open_libraries(lua_State *state);
	static void create_node_store(lua_State *state, MakeIt::Node *node);
	static int versions(lua_State *state);
};