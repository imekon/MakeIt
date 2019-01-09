#pragma once

extern void console_print(const char *text);
extern void console_clear();

class Console
{
public:
	void print(const char *format, ...);
};