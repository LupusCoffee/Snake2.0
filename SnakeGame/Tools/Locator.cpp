#include "Locator.h"
#include <assert.h>
#include <iostream>

#include "stdafx.h"

std::map<std::string, IService*> Locator::services;

bool Locator::Init()
{
	StateMachine* m_stateMachine = new StateMachine(State::MENU_STATE);
	SnakeGraphics* m_graphics = new SnakeGraphics(1000, 1000, WORLD_WIDTH, WORLD_HEIGHT);

	ProvideService("StateMachine", m_stateMachine);
	ProvideService("SnakeGraphics", m_graphics);

	for (auto m_service : services)
	{
		if (!m_service.second->Init())
		{
			std::cerr << "Failed to initialize service '" + m_service.first + "'!" << "\n";
			return false;
		}
	}

	return true;
}

void Locator::CleanUp()
{
	//TO-DO: fix the order dependency, or at the very least make sure it's not deeper than this.
	services.at("StateMachine")->CleanUp();
	delete services.at("StateMachine");

	services.at("SnakeGraphics")->CleanUp();
	delete services.at("SnakeGraphics");

	services.clear();
}

IService* Locator::GetService(std::string mapKey)
{
	if (services.find(mapKey) == services.end())
		assert(("Could not find service '" + mapKey + "'.").c_str());

	return services[mapKey];
}

void Locator::ProvideService(std::string mapKey, IService* service)
{
	if (!services.try_emplace(mapKey, service).second)
		assert(("Service '" + mapKey + "' already exists.").c_str());
}

