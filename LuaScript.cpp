#include <Box2d.h>

#include "Console.h"
#include "LuaScript.h"

Console *LuaScript::console = nullptr;
lua_State *LuaScript::state = nullptr;

void LuaScript::initialise(Console *cons)
{
	console = cons;

	state = luaL_newstate();

	luaL_openlibs(state);

	register_functions(state);
	Console::register_functions(state);
}

void LuaScript::shutdown()
{
	lua_close(state);
}

void LuaScript::process(const char *buffer)
{
	int error = luaL_loadbuffer(state, buffer, strlen(buffer), "process") || lua_pcall(state, 0, 0, 0);
	if (error)
	{
		console->print(lua_tostring(state, -1));
		lua_pop(state, 1);
	}
}

void LuaScript::register_functions(lua_State *state)
{
	lua_register(state, "versions", versions);
}

int LuaScript::versions(lua_State *state)
{
	console->print("MakeIt Game Engine V0.1 (c) 2019 Pete Goodwin\n");
	console->print("ImGui version: %s\n", ImGui::GetVersion());
	console->print("Box2D version: %d.%d.%d\n", b2_version.major, b2_version.minor, b2_version.revision);
	console->print("Lua version %s.%s.%s\n", LUA_VERSION_MAJOR, LUA_VERSION_MINOR, LUA_VERSION_RELEASE);

	return 0;
}