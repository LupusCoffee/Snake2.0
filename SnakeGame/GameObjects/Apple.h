#pragma once
#include "GameObject.h"

class Apple : public GameObject
{
public:
	Apple(std::vector<WorldTag*> worldMatrix, Vector2 position = Vector2(0, 0), Color bgColor = WHITE_COLOR, Color patternColor = WHITE_COLOR)
	: GameObject(position, bgColor, patternColor), worldMatrix(worldMatrix)
	{}
	Apple(std::vector<WorldTag*> worldMatrix, int x = 0, int y = 0, Color bgColor = WHITE_COLOR, Color patternColor = WHITE_COLOR)
	: GameObject(x, y, bgColor, patternColor), worldMatrix(worldMatrix)
	{}
	~Apple() override;

	void Update(float deltaTime) override;
	void Render() override;
	void CleanUp() override;

private:
	void CheckCollision();
	void SetRandomPosition();

	std::vector<WorldTag*> worldMatrix;
};

