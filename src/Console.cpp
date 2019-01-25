#include <stdio.h>
#include <stdarg.h>
//#include <spdlog/sinks/basic_file_sink.h>

#include "Console.h"

using namespace luabridge;

Console *Console::console = nullptr;

Console::Console() : scroll_to_bottom(false), _priority(PRIORITY::LOW)
{
	//auto logger = spdlog::basic_logger_mt("logger", "logs/logger.log");
}

void Console::add_command(const char *command)
{
	_commands.push_back(command);
}

void Console::print(const char *format, ...)
{
	if (format == nullptr)
		return;

	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsprintf(buffer, format, args);

	//spdlog::get("logger")->info(buffer);

	auto index = 0;
	char chunk[1024];

	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != '\n')
			chunk[index++] = buffer[i];
		else
		{
			chunk[index] = 0;

			ConsoleContent cont;
			cont.colour = get_priority_colour(_priority);
			cont.newLine = true;
			cont.text = chunk;
			content.push_back(cont);

			index = 0;
		}
	}

	if (index)
	{
		chunk[index] = 0;

		ConsoleContent cont;
		cont.colour = get_priority_colour(_priority);
		cont.newLine = false;
		cont.text = chunk;
		content.push_back(cont);
	}

	scroll_to_bottom = true;

	va_end(args);
}

bool Console::print_error(const char *message)
{
	if (message == nullptr)
		return false;

	auto priority = _priority;
	_priority = PRIORITY::HIGH;
	print("%s\n", message);
	_priority = priority;

	return true;
}

void Console::lua_print(const char *message)
{
	getInstance()->print("%s\n", message);
}

void Console::register_class(lua_State * state)
{
	getGlobalNamespace(state)
		.addFunction("print", lua_print)
		.beginNamespace("Console")
		.addFunction("print", lua_print)
		.endNamespace();
}

ImVec4 Console::get_priority_colour(PRIORITY priority)
{
	switch (priority)
	{
	case PRIORITY::HIGH:
		return ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

	case PRIORITY::MEDIUM:
		return ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

	case PRIORITY::LOW:
		return ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
	}

	return ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
}

void Console::shutdown()
{
	if (console)
		delete console;

	console = nullptr;
}