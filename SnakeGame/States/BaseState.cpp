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

void BaseState::Update()
{
}

void BaseState::Render()
{
}

void BaseState::CleanUp()
{
	m_snakeGraphics->ClearScreen(); //fucks up when we close the window, due to the graphics being destroyed before we get here
	m_snakeGraphics = nullptr;
}

void BaseState::KeyDown(int Key)
{
}