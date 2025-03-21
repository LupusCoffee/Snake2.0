#pragma once

class Game
{
public:
	void Run();

private:
	const int FPS = 60;

	SnakeGraphics* m_snakeGraphics = nullptr;

	float m_deltaTime = 0.0f;


	bool Init();

	void Update();

	void Render();

	void CleanUp();

	void KeyDownCallback(int Key);
};

