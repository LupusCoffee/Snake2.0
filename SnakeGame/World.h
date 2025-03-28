#pragma once
#include <string>
#include <vector>

#include "Agent/PlayerAgent.h"
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
	void UpdateGameObjects(float deltaTime);
	void RenderGameObjects();
	void DestroyGameObjects();
	void CleanUp();

	void KeyDownGameObjects(int Key); // i don't like this

	std::vector<WorldTag>* GetWorldMatrix();

private:
	bool LoadLevel(Level level);

	SnakeGraphics* m_graphics = nullptr;

	std::string levelString;

	std::vector<WorldTag>* worldMatrix = nullptr;
	std::vector<GameObject*> gameObjects;

	PlayerAgent* playerAgent = nullptr;
};

