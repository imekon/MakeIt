#pragma once

#include <vector>

#include "Object.h"

#ifdef _DEBUG
class MemoryMonitor
{
public:
	MemoryMonitor();

	void add_constructor(MakeIt::Object *ptr);
	void remove_constructor(MakeIt::Object *ptr);
	void report();

	static MemoryMonitor *get_instance() { return instance; }

private:
	std::vector<MakeIt::Object *> pointers;
	static MemoryMonitor *instance;
};

#define ENGINE_CONSTRUCTOR(x) MemoryMonitor::get_instance()->add_constructor(x);
#define ENGINE_DESTRUCTOR(x) MemoryMonitor::get_instance()->remove_constructor(x);
#else
#define ENGINE_CONSTRUCTOR(x)
#endif