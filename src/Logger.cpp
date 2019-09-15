#include "Engine.h"
#include <stdio.h>
#include <stdarg.h>

#include "Logger.h"

using namespace std;
using namespace luabridge;

Logger *Logger::instance = nullptr;

Logger::Logger(const char * filename) : enable(false), filename(filename)
{
	instance = this;
}

Logger::~Logger()
{
	close();
}

void Logger::open()
{
	file.open(filename, ios::binary);
}

void Logger::close()
{
	file.close();
}

void Logger::log(const char * format, ...)
{
	if (!enable)
		return;

	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsprintf_s(buffer, format, args);
	va_end(args);

	file << buffer;
}

void Logger::set_enable(bool value)
{
	auto logger = get_instance();
	if (logger)
	{
		if (logger->enable != value)
		{
			logger->enable = value;

			if (logger->enable)
				logger->open();
			else
				logger->close();
		}
	}
}

void Logger::register_class(lua_State *state)
{
	getGlobalNamespace(state).beginClass<Logger>("Logger")
		.addStaticFunction("enable", set_enable)
		.endClass();
}