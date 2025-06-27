#pragma once

#include <string>
#include <iostream>

enum Engine
{
	GM = 1,
	TOYOTA,
	WIA,
	BROKEN
};

class IEngine
{
public:
	virtual std::string getName() = 0;
	virtual Engine getType() = 0;
};

class GmEngine : public IEngine
{
public:
	std::string getName() override;
	Engine getType() override;
};

class ToyotaEngine : public IEngine
{
public:
	std::string getName() override;
	Engine getType() override;
};

class WiaEngine : public IEngine
{
public:
	std::string getName() override;
	Engine getType() override;
};

class BrokenEngine : public IEngine
{
public:
	std::string getName(void) override;
	Engine getType() override;
};

class EngineFactory
{
public:
	IEngine* getEngine(Engine engine_type);
};
