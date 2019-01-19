#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <lua.hpp>

namespace MakeIt
{
	class Physics;

	class Node
	{
	public:
		Node();
		virtual ~Node();

		virtual const char * get_name() const { return _name.c_str(); }
		virtual void set_name(const char *text) { _name = text; }
		virtual void add_child(Node *child);
		virtual void remove_child(Node *child);
		virtual std::vector<Node *> & get_children() { return _children; }
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
		std::string _name;
		std::vector<Node *> _children;

		static int _name_counter;
	};
}
