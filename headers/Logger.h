#pragma once

#include <iostream>
#include <fstream>

#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

class Logger
{
public:
	Logger(const char *filename);
	~Logger();

	void log(const char *format, ...);

	static Logger *get_instance() { return instance; }
	static void set_enable(bool value);
	static void register_class(lua_State *state);

private:
	bool enable;
	std::string filename;
	std::ofstream file;

	void open();
	void close();

	static Logger *instance;
};