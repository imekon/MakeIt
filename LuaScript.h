#pragma once

extern "C"
{
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

class LuaScript
{
public:
	static void initialise();
	static void shutdown();

private:
	static lua_State *state;

	static int versions(lua_State *state);
};