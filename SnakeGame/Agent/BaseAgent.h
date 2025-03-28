#pragma once
#include "../Tools/InclusionHelper.h"

class BaseAgent
{
public:
	BaseAgent() {};

	virtual Vector2 GetDirection() = 0;
	virtual void KeyDown(int Key) = 0;
};
