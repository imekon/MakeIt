#pragma once

#include <lua.hpp>

class Console;

class LuaScript
{
public:
	static void initialise(Console *cons);
	static void shutdown();

	static void process(const char *buffer);

private:
	static Console *console;
	static lua_State *state;

	static void register_functions(lua_State *state);
	static int versions(lua_State *state);
};