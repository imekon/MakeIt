#include "Engine.h"
#include "Logger.h"
#include "Node.h"

using namespace std;
using namespace MakeIt;

#ifdef ENABLE_MEMORY_MONITOR
MemoryMonitor *MemoryMonitor::instance = nullptr;

MemoryMonitor::MemoryMonitor()
{
	instance = this;
}

void MemoryMonitor::add_constructor(Object * ptr)
{
	pointers.push_back(ptr);
}

void MemoryMonitor::remove_constructor(Object * ptr)
{
	auto iter = find(pointers.begin(), pointers.end(), ptr);
	if (iter == pointers.end())
	{
		Logger::get_instance()->log("MemoryMonitor: name: %s type: %s pointer %p not in list\n", ptr->get_name(), ptr->get_type_name(), ptr);
		return;
	}

	pointers.erase(iter);
}

void MemoryMonitor::report()
{
	auto logger = Logger::get_instance();

	logger->log("MemoryMonitor: %d allocated\n", pointers.size());
}
#endif
