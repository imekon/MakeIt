#pragma once

#include <string>

namespace MakeIt
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		virtual const char * get_name() const { return _name.c_str(); }
		virtual const char * get_type_name() const { return "Node"; }
		virtual void set_name(const char *text) { _name = text; }

	protected:
		std::string _name;

		static int _name_counter;
	};
}
