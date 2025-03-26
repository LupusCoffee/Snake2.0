#pragma once
#include <string>

#include "IService.h"
#include "StateMachine.h"
#include "SnakeGraphics.h"
#include <map>

class Locator
{
public:
	static bool Init();
	static void CleanUp();

	static IService* GetService(std::string mapKey);
	static void ProvideService(std::string mapKey, IService* service);

private:
	static std::map<std::string, IService*> services;
};

