#include "GameState.h"

#include <iostream>

GameState::~GameState()
{
	std::cout << "Game State Killed \n";
}

bool GameState::Init()
{
	if (!BaseState::Init())
	{
		std::cout << "Game State Init Failure! \n";
		return false;
	}

	world = World(LEVEL2);
	world.CreateGameObjects();

	return true;
}

void GameState::Update(float deltaTime)
{
	if (!hasStarted) return;

	world.UpdateGameObjects(deltaTime);
}

void GameState::Render()
{
	if (!world.RenderLevel()) //render level
	{
		std::cerr << "Level cannot be rendered! \n";
		return;
	}

	world.RenderGameObjects();

	if (!hasStarted) m_snakeGraphics->PlotText(20, 5, 1, PURE_BLACK_COLOR, L"PRESS ENTER TO START", WHITE_COLOR, SnakeGraphics::Left);
}

void GameState::CleanUp()
{
	world.CleanUp();

	BaseState::CleanUp();
}

void GameState::KeyDown(int Key)
{
	if (Key == 13 || Key == 32)
	{
		hasStarted = true;
		//lazy bum!!!
		m_snakeGraphics->PlotText(20, 5, 1, PURE_BLACK_COLOR, L"PRESS ENTER TO START", PURE_BLACK_COLOR, SnakeGraphics::Left);
	}

	if (!hasStarted) return;

	world.KeyDownGameObjects(Key);
}
