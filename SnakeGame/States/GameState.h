#pragma once
#include "BaseState.h"
#include "../World.h"

class GameState : public BaseState
{
public:
	GameState() = default;
	~GameState() override;

	bool Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void CleanUp() override;

	void KeyDown(int Key) override;

private:
	World world;

	bool hasStarted = false;
};
