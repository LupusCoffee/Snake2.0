#include "stdafx.h"
#include "Game.h"
#include "Tools/SnakeGraphics.h"
#include "Tools/SnakeInput.h"
#include <iostream>
#include <chrono>
#include <thread>


bool Game::Init()
{
	// Init snake graphics
	m_snakeGraphics = new SnakeGraphics(1000, 1000, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!m_snakeGraphics->Init())
	{
		std::cerr << "Failed to initilize snake graphics!" << std::endl;

		return false;
	}

	// Init snake input
	SnakeInput::Init(m_snakeGraphics);

	SnakeInput::AddKeyDownCallback(std::bind(&Game::KeyDownCallback, this, std::placeholders::_1));

	return true;
}

void Game::KeyDownCallback(int Key)
{
	std::cout << "Keydown: " << Key << std::endl;
}

void Game::Update()
{

}

void Game::Render()
{
	//render current state

	m_snakeGraphics->Render();
}

void Game::CleanUp()
{
	SnakeInput::CleanUp();

	delete m_snakeGraphics;
	m_snakeGraphics = nullptr;
}

void Game::Run()
{
	if (!Init())
	{
		std::cerr << "Init failed!" << std::endl;

		return;
	}

	std::chrono::system_clock::time_point timer = std::chrono::system_clock::now();
	
	while (m_snakeGraphics->UpdateWindowMessages())
	{
		Update();

		Render();

		#pragma region Timy Whimy
		std::chrono::duration<double, std::milli> work_time = std::chrono::system_clock::now() - timer;
		long timeLeft = (1000 / FPS) - (long)work_time.count();
		if (timeLeft > 0) std::this_thread::sleep_for(std::chrono::milliseconds(timeLeft));
		std::chrono::duration<double, std::milli> deltaTime = std::chrono::system_clock::now() - timer;
		m_deltaTime = (float)deltaTime.count() / 1000.0f;
		timer = std::chrono::system_clock::now();
		#pragma endregion
	}

	CleanUp();
}
