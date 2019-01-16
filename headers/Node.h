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

		static void register_class(lua_State *state);

	protected:
		bool _visible;
		std::vector<Node *> _children;
	};
}
