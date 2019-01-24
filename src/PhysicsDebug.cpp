#include "PhysicsDebug.h"

using namespace MakeIt;

PhysicsDebug::PhysicsDebug()
{
	SetFlags(e_shapeBit);
}

void PhysicsDebug::draw(sf::RenderWindow * window)
{
}

void PhysicsDebug::DrawPolygon(const b2Vec2 * vertices, int32 vertexCount, const b2Color & color)
{
}

void PhysicsDebug::DrawSolidPolygon(const b2Vec2 * vertices, int32 vertexCount, const b2Color & color)
{
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
