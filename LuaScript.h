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

	static luaL_Reg library[];
	static luaL_Reg libraries[];

	static int open_library(lua_State *state);
	static void open_libraries(lua_State *state);
	static int versions(lua_State *state);
};