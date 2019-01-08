#include "LuaScript.h"

lua_State *LuaScript::state = nullptr;

void LuaScript::initialise()
{
	state = luaL_newstate();

	luaL_openlibs(state);
}

void LuaScript::shutdown()
{
	lua_close(state);
}

int LuaScript::versions(lua_State *state)
{
	return 0;
}