#include "GameObject.h"

#include <iostream>

GameObject::~GameObject()
{
	std::cout << "Deleting game object. \n";
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Render()
{
	//derender previous position
	m_graphics->ClearTile(prevPosition.x, prevPosition.y);

	//render my position
	m_graphics->PlotTile(position.x, position.y, 10, bgColor, patternColor, ' ');
}

void GameObject::CleanUp()
{
	std::cout << "clean up?";
	m_graphics = nullptr;
}

void GameObject::SetPosition(int x, int y)
{
	prevPosition = position;
	position.x = x;
	position.y = y;
}

void GameObject::SetPosition(Vector2 vector2)
{
	prevPosition = position;
	position = vector2;
}

void GameObject::AddPosition(int x, int y)
{
	SetPosition(position + Vector2(x,y));
}

void GameObject::AddPosition(Vector2 vector2)
{
	SetPosition(position + vector2);
}

const Vector2 GameObject::GetPosition()
{
	return position;
}

const Vector2 GameObject::GetPreviousPosition()
{
	return prevPosition;
}
