#pragma once
#include "GameObject.h"
#include "../Agent/PlayerAgent.h"

//hmmmmm do i need to use a vector for the snake tail? cant i just use pointers?
/*struct TailObject
{
public:
	GameObject* child;
	GameObject* AddChild(int length)
	{
		if (length == 0) return new GameObject;
		child = AddChild(length - 1);
		return child;
	}
};*/

class Snake : public GameObject
{
public:
	Snake(BaseAgent* agent, int tailLength = 3, float moveFrequency = 0.5f, Vector2 position = Vector2(0,0), Color bgColor = WHITE_COLOR, Color patternColor = WHITE_COLOR)
		: GameObject(position, bgColor, patternColor), agent(agent), moveFrequency(moveFrequency)
	{
		AddTail(tailLength);
	}
	Snake(BaseAgent* agent, int tailLength = 3, float moveFrequency = 0.5f, int x = 0, int y = 0, Color bgColor = WHITE_COLOR, Color patternColor = WHITE_COLOR)
	: GameObject(x,y,bgColor, patternColor), agent(agent), moveFrequency(moveFrequency)
	{
		AddTail(tailLength);
	}

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void CleanUp();

	void MoveTowards(Vector2 _direction);

	void AddTail(int length);
	void MoveTail();

	void CheckCollisions();
	void UpdateColliders();

private:
	BaseAgent* agent = nullptr;

	float moveFrequency;
	float speedTimer;

	std::vector<GameObject> snakeTail; //to-do: change this function to use only pointers to the previous tail obj
};
