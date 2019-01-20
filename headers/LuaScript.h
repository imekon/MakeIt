#pragma once

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Node.h"

class Console;

enum class DATA
{
	VECTOR,
	TEXTURE,
	NODE
};

struct GenericDataStore
{
	int magic;
	DATA type;
	void *data;
};

class LuaScript
{
public:
	static void initialise(Console *cons);
	static void shutdown();

	static bool load_file(const char *filename);
	static bool process(const char *buffer);
	static bool process_configuration(int &width, int &height, char *title, int length);
	static bool execute_function(const char *function_name);
	static bool execute_function(const char *function_name, float arg1);

	static void create_texture_store(lua_State *state, sf::Texture *texture);
	static void create_vector_store(lua_State *state, MakeIt::Vector2 *vector);
	static void create_node_store(lua_State *state, MakeIt::Node *node);

private:
	static bool running;
	static Console *console;
	static lua_State *state;

	static void register_class(lua_State *state);
	static void register_classes(lua_State *state);
	static void versions();
	static bool execute(int args);
};