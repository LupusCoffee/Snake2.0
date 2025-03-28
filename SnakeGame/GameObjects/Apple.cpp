#include "Apple.h"

#include "../Tools/stdafx.h"

Apple::~Apple()
{
}

void Apple::Update(float deltaTime)
{
	CheckCollision();
}

void Apple::Render()
{
	GameObject::Render();
}

void Apple::CleanUp()
{
	for (auto element : worldMatrix) element = nullptr;
	worldMatrix.clear();

	GameObject::CleanUp();
}

void Apple::CheckCollision()
{
	if (worldMatrix[0] == nullptr) return;

	if (worldMatrix[GetPosition().x + GetPosition().y * WORLD_HEIGHT]->tag == Tag::OBSTACLE)
		SetRandomPosition();
}

void Apple::SetRandomPosition()
{
	SetPosition(rand() % WORLD_WIDTH, rand() % WORLD_HEIGHT);

	if (worldMatrix[0] == nullptr) return;

	if (worldMatrix[GetPosition().x + GetPosition().y * WORLD_HEIGHT]->tag == Tag::OBSTACLE)
		SetRandomPosition();

	worldMatrix[GetPosition().x + GetPosition().y * WORLD_HEIGHT]->tag = Tag::COLLECTABLE;
}
