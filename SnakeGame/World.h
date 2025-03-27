#pragma once
#include <string>
#include <vector>

#include "GameObjects/GameObject.h"
#include "Tools/InclusionHelper.h"
#include "Tools/SnakeGraphics.h"

enum Level { LEVEL1, LEVEL2, LEVEL3 };

class World
{
public:
	World(Level startLevel = LEVEL1);

	bool RenderLevel();

	void CreateGameObjects();
	void UpdateGameObjects();
	void RenderGameObjects();
	void DestroyGameObjects();
	void CleanUp();

	void KeyDownGameObjects(int Key); // i don't like this

	Tag** GetWorldMatrix();

private:
	bool LoadLevel(Level level);

	SnakeGraphics* m_graphics = nullptr;

	std::string levelString;

	Tag** worldMatrix = nullptr; //make it a vector of Vector2

	std::vector<GameObject*> gameObjects;
	//PlayerAgent* playerBrain;
};

