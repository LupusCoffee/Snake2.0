#pragma once
class IService
{
public:
	virtual ~IService() = default;

	virtual bool Init() = 0;
	virtual void CleanUp() = 0;
};