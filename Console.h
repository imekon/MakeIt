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
	void print(const char *format, ...);

	const std::vector<ConsoleContent> & getContent() const { return content; }

	static Console *getInstance()
	{
		if (console == nullptr)
			console = new Console();

		return console;
	}

	static void register_functions(lua_State *state);
	static int print_feature(lua_State *state);

private:
	PRIORITY priority;
	std::vector<ConsoleContent> content;

	static Console *console;

	ImVec4 getPriorityColour(PRIORITY priority);
};