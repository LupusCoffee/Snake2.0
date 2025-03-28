#pragma once
#include <vector>

#include "BaseState.h"
#include "../Tools/SnakeGraphics.h"
#include "../Tools/ColorHelper.h"

enum class MenuOptionEnum
{
	PLAY = 0,
	ABOUT = 1,
	EXIT = 2
};

struct MenuOptionData
{
public:
	MenuOptionData() = default;
	MenuOptionData(MenuOptionEnum menuOption, const wchar_t* menuOptionText)
	: optionEnum(menuOption), m_menuOptionText(menuOptionText) {}

	MenuOptionEnum optionEnum = MenuOptionEnum::PLAY;
	const wchar_t* m_menuOptionText = L"Play"; //is this a pointer i need to delete??

	void Render(SnakeGraphics* graphics, int x, int y, int order, Color textColor, Color bgColor)
	{
		graphics->PlotText(x, y, order, bgColor, m_menuOptionText, textColor, SnakeGraphics::Left);
	}
};

struct Menu
{
public:
	Menu() = default;
	Menu(const wchar_t* menuTitle, const std::vector<MenuOptionData>& menuOptions)
	: m_menuTitle(menuTitle), m_menuOptions(menuOptions) {}

	const wchar_t* m_menuTitle;
	Color titleTextColor = WHITE_COLOR;
	Color titleBgColor = RED_COLOR;

	std::vector<MenuOptionData> m_menuOptions;
	Color idleItemTextColor = WHITE_COLOR;
	Color idleItemBgColor = PURE_BLACK_COLOR;
	Color hoverItemTextColor = PURE_BLACK_COLOR;
	Color hoverItemBgColor = RED_COLOR;

	void Render(SnakeGraphics* graphics, int currentMenuOption, int x, int y, int order)
	{
		graphics->PlotText(x, y, order, titleBgColor, m_menuTitle, titleTextColor, SnakeGraphics::Left);
		int i = 1; //hmmm for i instead of for each?
		for (auto menuOption : m_menuOptions)
		{
			if (currentMenuOption == static_cast<int>(menuOption.optionEnum))
				menuOption.Render(graphics, x, y + i, order, hoverItemTextColor, hoverItemBgColor);
			else
				menuOption.Render(graphics, x, y + i, order, idleItemTextColor, idleItemBgColor);
			i++;
		}
	}
};

class MenuState : public BaseState
{
public:
	MenuState() = default;
	~MenuState() override;

	bool Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void CleanUp() override;

	void KeyDown(int Key) override;

private:
	Menu m_menu;
	int m_menuOption = 0;
};
