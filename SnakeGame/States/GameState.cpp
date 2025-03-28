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
}

void GameState::CleanUp()
{
	world.CleanUp();

	world.DestroyGameObjects();

	BaseState::CleanUp();
}

void GameState::KeyDown(int Key)
{
	world.KeyDownGameObjects(Key);
}
