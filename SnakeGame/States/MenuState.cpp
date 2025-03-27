#include "MenuState.h"
#include <iostream>
#include "../Tools/Locator.h"

MenuState::~MenuState()
{
	std::cout << "Menu State Killed \n";
}

bool MenuState::Init()
{
	if (!BaseState::Init())
	{
		std::cout << "Menu State Init Failure! \n";
		return false;
	}

	m_menu = Menu
	(
		L"SUNEIKU DA!!",
		{
		MenuOptionData(MenuOptionEnum::PLAY, L"Play"),
		MenuOptionData(MenuOptionEnum::ABOUT, L"About"),
		MenuOptionData(MenuOptionEnum::EXIT, L"Exit")
	});

	return true;
}

void MenuState::Update()
{
	
}

void MenuState::Render()
{
	if (m_snakeGraphics == nullptr) return;
	m_menu.Render(m_snakeGraphics, m_menuOption, 24, 60/3+4, 1);
}

void MenuState::CleanUp()
{
	m_menuOption = 0;
	m_menu = Menu();

	BaseState::CleanUp();
}

void MenuState::KeyDown(int Key)
{
	//Menu Options - could use an interface for each menu item but it's whatever for now
	if (Key == 13 || Key == 32)
	{
		if (m_menuOption == (int)MenuOptionEnum::PLAY)
			dynamic_cast<StateMachine*>(Locator::GetService("StateMachine"))->SetState(GAME_STATE);
		if (m_menuOption == (int)MenuOptionEnum::ABOUT)
		{
			std::cout << "Imagine thinking i'd have an about page \n";
		}
		if (m_menuOption == (int)MenuOptionEnum::EXIT)
			DestroyWindow(m_snakeGraphics->GetHwnd());
	}

	//up
	if (Key == 87 || Key == 38)
	{
		m_menuOption--;
		if (m_menuOption < 0) m_menuOption = 2;
	}
	//down
	else if (Key == 83 || Key == 40)
	{
		m_menuOption++;
		if (m_menuOption > 2) m_menuOption = 0;
	}
}