#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <lua.hpp>
#include <LuaBridge.h>
#include <RefCountedPtr.h>

#include "Object.h"

namespace MakeIt
{
	class Physics;

	class Node : public Object
	{
	public:
		Node();
		virtual ~Node();

		virtual void add_child(luabridge::RefCountedPtr<Node> child);
		virtual void remove_child(luabridge::RefCountedPtr<Node> child);
		virtual std::vector<luabridge::RefCountedPtr<Node>> & get_children() { return _children; }
		virtual void draw(sf::RenderWindow *window);
		virtual bool get_visible() const { return _visible; }
		virtual void set_visible(bool visible) { _visible = visible; }
		virtual void update(Physics *physics);

		int get_z() const { return _z; }
		void set_z(int z) { _z = z; }

		void sort();

		static void register_class(lua_State *state);

	protected:
		bool _visible;
		int _z;
		std::vector<luabridge::RefCountedPtr<Node>> _children;
	};
}
