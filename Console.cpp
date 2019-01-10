#include <stdio.h>
#include <stdarg.h>

#include "Console.h"

Console::Console() : priority(PRIORITY::LOW)
{

}

void Console::print(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsprintf_s(buffer, format, args);
	ConsoleContent cont;
	cont.colour = getPriorityColour(priority);
	cont.newLine = false;
	cont.text = buffer;
	content.push_back(cont);

	va_end(args);
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
