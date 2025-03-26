#include "Locator.h"
#include <assert.h>
#include <iostream>

#include "stdafx.h"

std::map<std::string, IService*> Locator::services;

bool Locator::Init()
{
	SnakeGraphics* m_graphics = new SnakeGraphics(1000, 1000, SCREEN_WIDTH, SCREEN_HEIGHT);
	StateMachine* m_stateMachine = new StateMachine(State::MENU_STATE);

	ProvideService("SnakeGraphics", m_graphics);
	ProvideService("StateMachine", m_stateMachine);

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
	for (auto m_service : services)
	{
		m_service.second->CleanUp();
		delete m_service.second;
	}
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

