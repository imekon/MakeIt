#include "Physics.h"
#include "PhysicsDebug.h"

using namespace MakeIt;

PhysicsDebug::PhysicsDebug()
{
	SetFlags(e_shapeBit);
}

void PhysicsDebug::draw(sf::RenderWindow * window)
{
	for (auto shape : shapes)
	{
		window->draw(shape);
	}

	shapes.clear();
}

void PhysicsDebug::DrawPolygon(const b2Vec2 * vertices, int32 vertexCount, const b2Color & color)
{
}

void PhysicsDebug::DrawSolidPolygon(const b2Vec2 * vertices, int32 vertexCount, const b2Color & color)
{
	auto physics = Physics::get_physics();

	sf::ConvexShape shape;
	shape.setPointCount(vertexCount);
	for (int i = 0; i < vertexCount; i++)
	{
		shape.setPoint(i, sf::Vector2f(vertices[i].x * physics->get_scaling(), vertices[i].y * physics->get_scaling()));
	}

	//shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color(color.r * 255, color.g * 255, color.b * 255));

	shapes.push_back(shape);
}

void PhysicsDebug::DrawCircle(const b2Vec2 & center, float32 radius, const b2Color & color)
{
}

void PhysicsDebug::DrawSolidCircle(const b2Vec2 & center, float32 radius, const b2Vec2 & axis, const b2Color & color)
{
}

void PhysicsDebug::DrawSegment(const b2Vec2 & p1, const b2Vec2 & p2, const b2Color & color)
{
}

void PhysicsDebug::DrawTransform(const b2Transform & xf)
{
}

void PhysicsDebug::DrawPoint(const b2Vec2 & p, float32 size, const b2Color & color)
{
}
