#pragma once

enum class Tag { EMPTY, COLLECTABLE, OBSTACLE };

struct Vector2
{
public:
	Vector2(int x, int y) : x(x), y(y) {};

	int x = 0;
	int y = 0;

	const Vector2 operator+ (const Vector2 vector2)
	{
		return Vector2(x + vector2.x, y + vector2.y);
	}
};