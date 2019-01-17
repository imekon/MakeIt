#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <lua.hpp>

namespace MakeIt
{
	class Node
	{
	public:
		Node();
		virtual ~Node();

		virtual void add_child(Node *child);
		virtual void remove_child(Node *child);
		virtual void draw(sf::RenderWindow *window);
		virtual bool get_visible() const { return _visible; }
		virtual void set_visible(bool visible) { _visible = visible; }

		int get_z() const { return _z; }
		void set_z(int z) { _z = z; }

		void sort();

		static void register_class(lua_State *state);

	protected:
		bool _visible;
		int _z;
		std::vector<Node *> _children;
	};
}
