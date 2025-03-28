#include "PlayerAgent.h"

Vector2 PlayerAgent::GetDirection()
{
	return direction;
}

void PlayerAgent::KeyDown(int Key)
{
	#pragma region Handle Direction Input
	if (Key == keyUp)
	{
		if (direction.y != 1) direction = Vector2(0, -1);
	}
	if (Key == keyDown)
	{
		if (direction.y != -1) direction = Vector2(0, 1);
	}
	if (Key == keyLeft)
	{
		if (direction.x != 1) direction = Vector2(-1, 0);
	}
	if (Key == keyRight)
	{
		if (direction.x != -1) direction = Vector2(1, 0);
	}
	#pragma	endregion
}
