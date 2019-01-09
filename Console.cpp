#include <stdio.h>
#include <stdarg.h>

#include "Console.h"

void Console::print(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsprintf_s(buffer, format, args);
	console_print(buffer);
	va_end(args);
}