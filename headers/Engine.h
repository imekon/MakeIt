#pragma once

#include <vector>

#ifdef _DEBUG
class MemoryMonitor
{
public:
	MemoryMonitor();

	void add_constructor(void *ptr);
	void remove_constructor(void *ptr);

	static MemoryMonitor *get_instance() { return instance; }

private:
	std::vector<void *> pointers;
	static MemoryMonitor *instance;
};

#define ENGINE_CONSTRUCTOR(x) MemoryMonitor::get_instance()->add_constructor(x);
#define ENGINE_DESTRUCTOR(x) MemoryMonitor::get_instance()->remove_constructor(x);
#else
#define ENGINE_CONSTRUCTOR(x)
#endif