#pragma once

#include <vector>

#include "Node2D.h"

namespace MakeIt
{
	class Sprite : public Node2D
	{
	public:
		Sprite();
		virtual ~Sprite();

		const char *get_type_name() const override { return "Sprite"; }

		void set_position(const Vector2 *vector) override;
		void set_scale(const Vector2 *vector) override;
		void set_rotate(float angle) override;
		void set_global_position(const Vector2 *vector) override;
		void set_global_scale(const Vector2 *vector) override;

		const Vector2 &get_origin() const { return _origin; }
		void set_origin(const Vector2 *vector);
		void set_texture(Texture *texture);

		void draw(sf::RenderWindow *window) override;

		static void register_class(lua_State *state);

	private:
		sf::Sprite _sprite;
		Vector2 _origin;
	};
}