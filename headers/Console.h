#pragma once

#include <string>
#include <vector>

#include <imgui.h>

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include "Priority.h"

struct ConsoleContent
{
	bool newLine;
	ImVec4 colour;
	std::string text;
};

class Logger;

class Console
{
public:
	Console();
	~Console();

	void add_command(const char *command);
	void set_priority(PRIORITY prio) { _priority = prio; }
	void print(const char *format, ...);
	bool print_error(const char *message);
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

	static void register_class(lua_State *state);

private:
	Logger *logger;
	bool scroll_to_bottom;
	PRIORITY _priority;
	std::vector<std::string> _commands;

	std::vector<ConsoleContent> content;
	ImVec4 get_priority_colour(PRIORITY priority);

	static Console *console;
	static void lua_print(const char *message);
};