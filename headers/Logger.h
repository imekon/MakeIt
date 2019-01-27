#pragma once

#include <iostream>
#include <fstream>

class Logger
{
public:
	Logger(const char *filename);
	~Logger();

	void log(const char *format, ...);

	static Logger *get_instance() { return instance; }

private:
	std::ofstream file;

	static Logger *instance;
};