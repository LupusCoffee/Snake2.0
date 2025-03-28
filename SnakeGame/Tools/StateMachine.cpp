#include "StateMachine.h"
#include <iostream>

//to-do: fix this yo
#include "../States/GameState.h"
#include "../States/MenuState.h"
#include "../States/OutroState.h"

StateMachine::StateMachine(State defaultState)
{
	this->defaultState = defaultState;
}

bool StateMachine::Init()
{
	availableStates.insert
	({
		{MENU_STATE, new MenuState()},
		{GAME_STATE, new GameState()},
		{OUTRO_STATE, new OutroState()},
	});

	return SetState(defaultState);
}

void StateMachine::CleanUp()
{
	currentState->CleanUp();
	currentState = nullptr;

	for (auto element : availableStates)
		delete element.second;
	availableStates.clear();
}

BaseState* StateMachine::GetCurrentState()
{
	return currentState;
}

bool StateMachine::SetState(State newCurrentState)
{
	if (currentState != nullptr) currentState->CleanUp();

	if (!availableStates.count(newCurrentState))
	{
		std::cerr << "State '" << newCurrentState << "' not found!" << "\n";
		return false;
	}
	currentState = availableStates.at(newCurrentState);

	if (!currentState->Init())
	{
		std::cerr << "Failed to initialize state!" << "\n";
		return false;
	}

	return true;
}
