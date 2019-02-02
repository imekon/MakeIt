#pragma once

#include "Node.h"

namespace MakeIt
{
	class Scene : public Node
	{
	public:
		Scene();
		virtual ~Scene();

		const char *get_type_name() const override { return "Scene"; }

		static void register_class(lua_State *state);

		static void set_root(Scene *scene) { _root = scene; }
		static Scene *get_root() { return _root; }

	private:
		static Scene *_root;
	};
}