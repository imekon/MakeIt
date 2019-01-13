#pragma once

namespace MakeIt
{
	class Vector2
	{
	public:
		Vector2(float x, float y);

		float get_x() const { return x; }
		float get_y() const { return y; }

	private:
		float x, y;
	};
}