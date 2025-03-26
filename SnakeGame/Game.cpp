#include "Tools/stdafx.h"
#include "Game.h"
#include "Tools/SnakeGraphics.h"
#include "Tools/SnakeInput.h"
#include <iostream>
#include <chrono>
#include <thread>

#include "Tools/Locator.h"


bool Game::Init()
{
	//Init Locator
	if (!Locator::Init())
	{
		std::cerr << "Locator init failed!" << '\n';
		return false;
	}

	//Init services
	m_snakeGraphics = dynamic_cast<SnakeGraphics*>(Locator::GetService("SnakeGraphics"));
	m_stateMachine = dynamic_cast<StateMachine*>(Locator::GetService("StateMachine"));

	// Init snake input - I'll let snake graphics be here, is fine.
	SnakeInput::Init(m_snakeGraphics);
	SnakeInput::AddKeyDownCallback(std::bind(&Game::KeyDownCallback, this, std::placeholders::_1));

	return true;
}

void Game::KeyDownCallback(int Key)
{
	std::cout << "Keydown: " << Key << '\n';
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
	m_snakeGraphics = nullptr;
	m_stateMachine = nullptr;

	SnakeInput::CleanUp();
	Locator::CleanUp();
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

		#pragma region Timey Whimy
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
