#pragma once

#include <string>
#include <vector>

#include <imgui.h>

#include "Priority.h"

struct ConsoleContent
{
	bool newLine;
	ImVec4 colour;
	std::string text;
};

class Console
{
public:
	Console();
	void print(const char *format, ...);

	const std::vector<ConsoleContent> & getContent() const { return content; }

private:
	PRIORITY priority;
	std::vector<ConsoleContent> content;

	ImVec4 getPriorityColour(PRIORITY priority);
};