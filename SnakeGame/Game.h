#pragma once
#include "Tools/StateMachine.h"

class Game
{
public:
	void Run();

private:
	const int FPS = 60;
	float m_deltaTime = 0.0f;

	SnakeGraphics* m_snakeGraphics = nullptr;
	StateMachine* m_stateMachine = nullptr;


	bool Init();

	void Update();

	void Render();

	void CleanUp();

	void KeyDownCallback(int Key);
};

