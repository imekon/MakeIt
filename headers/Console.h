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
	bool get_scroll_to_bottom() const { return scroll_to_bottom; }
	void clear_scroll_to_bottom() { scroll_to_bottom = false; }

	const std::vector<ConsoleContent> & get_content() const { return content; }

	static Console *getInstance()
	{
		if (console == nullptr)
			console = new Console();

		return console;
	}

	static void shutdown();

	static int open_library(lua_State *state);

private:
	bool scroll_to_bottom;
	PRIORITY priority;
	std::vector<ConsoleContent> content;

	static Console *console;
	static luaL_Reg library[];

	ImVec4 get_priority_colour(PRIORITY priority);
	static int print_feature(lua_State *state);
};