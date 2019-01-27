#include <stdio.h>
#include <stdarg.h>

#include "Logger.h"

using namespace std;

Logger *Logger::instance = nullptr;

Logger::Logger(const char * filename)
{
	instance = this;

	file.open(filename, ios::binary);
}

Logger::~Logger()
{
	file.close();
}

void Logger::log(const char * format, ...)
{
	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsprintf(buffer, format, args);
	va_end(args);

	file << buffer;
}
