#include "Node2D.h"

using namespace MakeIt;

Node2D::Node2D() : translate(0.0f, 0.0f), scale(1.0f, 1.0f), rotate(0.0f)
{

}

Node2D::~Node2D()
{

}

void MakeIt::Node2D::set_translate(MakeIt::Vector2 vector)
{
	translate = vector;
}

void MakeIt::Node2D::set_scale(MakeIt::Vector2 vector)
{
	scale = vector;
}

void MakeIt::Node2D::set_rotate(float angle)
{
	rotate = angle;
}
