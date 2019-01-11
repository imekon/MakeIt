#include <stdio.h>
#include <stdarg.h>

#include "Console.h"

Console *Console::console = nullptr;

Console::Console() : priority(PRIORITY::LOW)
{

}

void Console::print(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsprintf_s(buffer, format, args);

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
			cont.colour = getPriorityColour(priority);
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
		cont.colour = getPriorityColour(priority);
		cont.newLine = false;
		cont.text = chunk;
		content.push_back(cont);
	}

	va_end(args);
}

void Console::register_functions(lua_State * state)
{
	lua_register(state, "print", print_feature);
}

int Console::print_feature(lua_State * state)
{
	auto console = getInstance();

	auto num_args = lua_gettop(state);

	for (int index = 1; index <= num_args; index++)
	{
		auto text = lua_tostring(state, index);
		
		console->print(text);
		console->print("\n");
	}

	return 0;
}

ImVec4 Console::getPriorityColour(PRIORITY priority)
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
