#pragma once

#include <string>
#include <vector>

#include <imgui.h>

#include <lua.hpp>

#include "Priority.h"

struct ConsoleContent
{
	bool newLine;
	ImVec4 colour;
	std::string text;
};

class Console
{
public:
	Console();

	void set_priority(PRIORITY prio) { priority = prio; }
	void print(const char *format, ...);

	const std::vector<ConsoleContent> & get_content() const { return content; }

	static Console *getInstance()
	{
		if (console == nullptr)
			console = new Console();

		return console;
	}

	static int open_library(lua_State *state);

private:
	PRIORITY priority;
	std::vector<ConsoleContent> content;

	static Console *console;
	static luaL_Reg library[];

	ImVec4 get_priority_colour(PRIORITY priority);
	static int print_feature(lua_State *state);
};