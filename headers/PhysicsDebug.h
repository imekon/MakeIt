#pragma once

#include <vector>
#include <Box2D/Common/b2Draw.h>
#include <SFML/Graphics.hpp>

namespace MakeIt
{
	class PhysicsDebug : public b2Draw
	{
	public:
		PhysicsDebug();
		virtual ~PhysicsDebug();

		void draw(sf::RenderWindow *window);

		void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
		void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
		void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) override;
		void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) override;
		void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;
		void DrawTransform(const b2Transform& xf) override;
		void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) override;

	private:
		std::vector<sf::ConvexShape> shapes;
	};
}