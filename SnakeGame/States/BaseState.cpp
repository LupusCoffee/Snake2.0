#include "BaseState.h"
#include <iostream>

#include "../Tools/Locator.h"

BaseState::BaseState()
{
}

BaseState::~BaseState()
{
	std::cout << "Base State Killed \n";
}

bool BaseState::Init()
{
	m_snakeGraphics = dynamic_cast<SnakeGraphics*>(Locator::GetService("SnakeGraphics"));
	return true;
}

void BaseState::Update(float deltaTime)
{
}

void BaseState::Render()
{
}

void BaseState::CleanUp()
{
	m_snakeGraphics->ClearScreen();
	m_snakeGraphics = nullptr;
}

void BaseState::KeyDown(int Key)
{
}