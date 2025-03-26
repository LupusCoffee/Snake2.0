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
	
}

void BaseState::KeyDown(int Key)
{

}