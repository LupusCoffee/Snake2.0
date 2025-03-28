#include "Snake.h"

void Snake::Update(float deltaTime)
{
	if (speedTimer < moveFrequency) speedTimer += deltaTime;
	else
	{
		MoveTowards(agent->GetDirection());
		CheckCollisions();
		UpdateColliders();
		speedTimer = 0;
	}
}

void Snake::Render()
{
	GameObject::Render(); //head
	for (auto tailObj : snakeTail) tailObj.Render(); //tail
}

void Snake::CleanUp()
{
	agent = nullptr;

	snakeTail.clear(); //tail
	GameObject::CleanUp(); //head
}


void Snake::MoveTowards(Vector2 _direction)
{
	MoveTail();
	AddPosition(_direction);
}


//????? keeps deleting game objects??? huh??????????
void Snake::AddTail(int length) //to-do: change this function to use only pointers to the previous tail obj
{
	for (int i = 0; i < length; ++i)
	{
		if (snakeTail.empty())
			snakeTail.emplace_back(GameObject(GetPreviousPosition(), RED_COLOR));
		else
		{
			//creates a game object at the previous position of the last snake tail object
			snakeTail.emplace_back(GameObject(snakeTail[snakeTail.size()-1].GetPreviousPosition(), RED_COLOR));
		}
	}
}

//????? keeps deleting game objects??? huh??????????
void Snake::MoveTail() //to-do: change this function to use only pointers to the previous tail obj
{
	for (int tailIndex = snakeTail.size()-1; -1 < tailIndex; --tailIndex)
	{
		if (tailIndex == 0) snakeTail[tailIndex].SetPosition(GetPosition());
		else
		{
			Vector2 parentTailObjPos = snakeTail[tailIndex - 1].GetPosition();
			snakeTail[tailIndex].SetPosition(parentTailObjPos);
		}
	}
}


void Snake::CheckCollisions()
{

}

void Snake::UpdateColliders()
{

}
