#pragma once
#include <map>

#include "IService.h"
#include "../States/BaseState.h"

enum State { MENU_STATE, GAME_STATE, OUTRO_STATE };

class StateMachine : public IService
{
public:
	StateMachine(State defaultState);
	bool Init();
	void CleanUp();

	BaseState* GetCurrentState();
	bool SetState(State newCurrentState);

private:
	std::map<State, BaseState*> availableStates;
	BaseState* currentState = nullptr;
	State defaultState = MENU_STATE;
};

