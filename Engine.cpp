#include "Engine.h"
#include "Logger.h"

using namespace std;

#ifdef _DEBUG
MemoryMonitor *MemoryMonitor::instance = nullptr;

MemoryMonitor::MemoryMonitor()
{
	instance = this;
}

void MemoryMonitor::add_constructor(void * ptr)
{
	pointers.push_back(ptr);
}

void MemoryMonitor::remove_constructor(void * ptr)
{
	auto iter = find(pointers.begin(), pointers.end(), ptr);
	if (iter == pointers.end())
	{
		Logger::get_instance()->log("MemoryMonitor: pointer %p not in list\n", ptr);
		return;
	}

	pointers.erase(iter);
}
#endif
