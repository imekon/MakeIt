#include <Box2d.h>

#include "Console.h"
#include "LuaScript.h"

luaL_Reg LuaScript::library[] =
{
	"versions", LuaScript::versions,

	nullptr, nullptr
};

luaL_Reg LuaScript::libraries[] =
{
	"System", LuaScript::open_library,
	"Console", Console::open_library,

	nullptr, nullptr
};

Console *LuaScript::console = nullptr;
lua_State *LuaScript::state = nullptr;

void LuaScript::initialise(Console *cons)
{
	console = cons;
	state = luaL_newstate();
	luaL_openlibs(state);
	open_libraries(state);
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

int LuaScript::open_library(lua_State *state)
{
	luaL_newlib(state, library);
	return 1;
}

void LuaScript::open_libraries(lua_State *state)
{
	lua_register(state, "versions", versions);

	luaL_Reg *lib;

	for (lib = libraries; lib->func; lib++)
	{
		luaL_requiref(state, lib->name, lib->func, 1);
		lua_pop(state, 1);
	}
}

int LuaScript::versions(lua_State *state)
{
	console->print("MakeIt Game Engine V0.1 (c) 2019 Pete Goodwin\n");
	console->print("ImGui version: %s\n", ImGui::GetVersion());
	console->print("Box2D version: %d.%d.%d\n", b2_version.major, b2_version.minor, b2_version.revision);
	console->print("Lua version %s.%s.%s\n", LUA_VERSION_MAJOR, LUA_VERSION_MINOR, LUA_VERSION_RELEASE);

	return 0;
}