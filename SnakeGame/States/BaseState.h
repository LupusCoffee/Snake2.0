#pragma once
class SnakeGraphics;

class BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	virtual bool Init();
	virtual void Update();
	virtual void Render();
	virtual void CleanUp();

	virtual void KeyDown(int Key);

protected:
	SnakeGraphics* m_snakeGraphics = nullptr;
};
