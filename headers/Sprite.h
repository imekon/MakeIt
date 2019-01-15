#pragma once

#include <vector>
#include <lua.hpp>
#include <SFML/Graphics.hpp>

#include "Node2D.h"

namespace MakeIt
{
	class Sprite : public Node2D
	{
	public:
		Sprite();
		virtual ~Sprite();

		void set_position(MakeIt::Vector2 vector) override;
		void set_scale(MakeIt::Vector2 vector) override;
		void set_rotate(float angle) override;

		Vector2 get_origin() const { return origin; }
		void set_origin(Vector2 vector);
		void set_texture(Texture *texture);

		int get_z() const { return _z; }
		void set_z(int z) { _z = z; }

		void draw(sf::RenderWindow *window);

		static void open_library(lua_State *state);

	private:
		int _z;
		sf::Sprite _sprite;
		Vector2 origin;
	};

	class SpriteManager
	{
	public:
		SpriteManager();
		~SpriteManager();

		void add_sprite(Sprite *sprite);
		void remove_sprite(Sprite *sprite);

		void draw(sf::RenderWindow *window);

		static SpriteManager *getInstance();
		static void shutdown();

	private:
		std::vector<Sprite *> sprites;

		static SpriteManager *instance;
	};
}