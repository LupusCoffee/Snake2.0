#include "stdafx.h"
#include "Game.h"
#include "crtdbg.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game game;

	game.Run();

	//AAHAHHH LEAAAAK
	int* ptr = new int;

	return 0;
}