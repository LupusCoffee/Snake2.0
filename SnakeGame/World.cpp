#include "World.h"
#include <fstream>
#include <iostream>

#include "GameObjects/Apple.h"
#include "GameObjects/Snake.h"
#include "Tools/ColorHelper.h"
#include "Tools/Locator.h"
#include "Tools/SnakeGraphics.h"
#include "Tools/stdafx.h"

World::World(Level startLevel)
{
	m_graphics = dynamic_cast<SnakeGraphics*>(Locator::GetService("SnakeGraphics"));

	//load level so it can be rendered
	if (!LoadLevel(startLevel)) std::cout << "Level failed to load. \n";

	playerAgent = new PlayerAgent(37, 38, 39, 40);
}

bool World::LoadLevel(Level level)
{
	std::string fileToLoad;

	switch (level)
	{
		case LEVEL1: fileToLoad = "Levels/Level1.txt"; break;
		case LEVEL2: fileToLoad = "Levels/Level2.txt"; break;
		case LEVEL3: fileToLoad = "Levels/Level3.txt"; break;
	}

	//add contents of readFile to levelString
	std::ifstream readFile(fileToLoad);
	if (!readFile) return false;

	levelString.assign((std::istreambuf_iterator<char>(readFile)), (std::istreambuf_iterator<char>()));

	if (levelString.empty()) return false;

	//set world matrix based on level string - maybe should be somewhere else?
	int x = 0, y = 0;
	for (int i = 0; i < levelString.size(); ++i)
	{
		if (levelString[i] == ' ') continue;

		if (levelString[i] == '\n')
		{
			x = 0;
			y++;
			continue;
		}

		if (levelString[i] == 'X' || levelString[i] == 'x') worldMatrix.push_back(new WorldTag(x,y,Tag::OBSTACLE));
		else worldMatrix.push_back(new WorldTag(x, y, Tag::EMPTY));
		x++;
	}

	return true;
}

bool World::RenderLevel()
{
	if (levelString.empty()) return false;

	//plot the level string as tiles
	int x = 0, y = 0;
	for (int i = 0; i < levelString.size(); ++i)
	{
		if (levelString[i] == ' ') continue;

		if (x == WORLD_WIDTH || levelString[i] == '\n')
		{
			x = 0;
			y++;
			continue;
		}

		if (levelString[i] == 'X' || levelString[i] == 'x')
			m_graphics->PlotTile(x, y, 0, OBSTACLE_COLOR, OBSTACLE_COLOR, ' ');
		x++;
	}

	return true;
}


void World::CreateGameObjects()
{
	//TO-DO: figure out a way for world matrix to not be here, and instead just reference it in snake somehow
	tempSnake = new Snake(playerAgent, worldMatrix, 3, 0.1f, Vector2(29, 28), RED_COLOR, RED_COLOR);
	gameObjects.push_back(tempSnake);
	gameObjects.push_back(new Apple(worldMatrix, Vector2(rand() % WORLD_WIDTH, rand() % WORLD_HEIGHT), TURQUOISE_COLOR, TURQUOISE_COLOR));
}

void World::UpdateGameObjects(float deltaTime)
{
	for (auto g_object : gameObjects)
		g_object->Update(deltaTime);

	//AAAAAAAAAAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGGGGGGGGGGGGGHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
	if (tempSnake->isDead) dynamic_cast<StateMachine*>(Locator::GetService("StateMachine"))->SetState(MENU_STATE);
}

void World::RenderGameObjects()
{
	for (auto g_object : gameObjects)
		g_object->Render();

	/*for (int i = 0; i < WORLD_WIDTH; i++)
	{
		for (int j = 0; j < WORLD_HEIGHT; j++)
		{
			if (worldMatrix[i+j*WORLD_HEIGHT]->tag == Tag::OBSTACLE)
				m_graphics->PlotTile(i, j, 20, Color(0, 0, 255), Color(0,255,0), 'X');
		}
	}*/
}

void World::DestroyGameObjects()
{
	for (auto g_object : gameObjects)
	{
		g_object->CleanUp();
		delete g_object;
		g_object = nullptr;
	}

	tempSnake = nullptr;

	gameObjects.clear();
}

void World::CleanUp()
{
	delete playerAgent;
	playerAgent = nullptr;

	for (auto element : worldMatrix)
	{
		delete element;
		element = nullptr;
	}
	worldMatrix.clear();

	m_graphics = nullptr;
}


void World::KeyDownGameObjects(int Key)
{
	playerAgent->KeyDown(Key);
}

std::vector<WorldTag*> World::GetWorldMatrix()
{
	return worldMatrix;
}
