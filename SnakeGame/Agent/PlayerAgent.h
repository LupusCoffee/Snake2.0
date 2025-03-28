#pragma once
#include "BaseAgent.h"
class PlayerAgent : public BaseAgent
{
public:
	PlayerAgent(int keyLeft = 0, int keyUp = 0, int keyRight = 0, int keyDown = 0)
	: keyLeft(keyLeft), keyUp(keyUp), keyRight(keyRight), keyDown(keyDown), direction(Vector2(1,0)) {}

	Vector2 GetDirection() override;
	void KeyDown(int Key) override;

private:
	int keyUp, keyDown, keyLeft, keyRight;
	Vector2 direction;
};
