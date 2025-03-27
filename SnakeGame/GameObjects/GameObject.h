#pragma once
#include <vector>
#include "../Tools/InclusionHelper.h"
#include "../Tools/ColorHelper.h"
#include "../Tools/Locator.h"
#include "../Tools/SnakeGraphics.h"

class GameObject
{
public:
	GameObject(int x = 0, int y = 0, Color bgColor = WHITE_COLOR, Color patternColor = WHITE_COLOR)
	: position(Vector2(x, y)), prevPosition(position), bgColor(bgColor), patternColor(patternColor)
	{
		m_graphics = dynamic_cast<SnakeGraphics*>(Locator::GetService("SnakeGraphics"));
	}
	virtual ~GameObject();

	virtual void Update();
	virtual void Render();
	virtual void CleanUp();

	virtual void SetPosition(int x, int y);
	virtual void SetPosition(Vector2 vector2);
	const Vector2 GetPosition();
	const Vector2 GetPreviousPosition();

protected:
	SnakeGraphics* m_graphics = nullptr;

	Color bgColor;
	Color patternColor;
	Vector2 position;
	Vector2 prevPosition;
};
