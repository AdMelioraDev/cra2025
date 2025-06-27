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
	std::string getName(void) override
	{
		return std::string("GM");
	}
	Engine getType() override
	{
		return GM;
	}
};

class ToyotaEngine : public IEngine
{
public:
	std::string getName(void) override
	{
		return std::string("TOYOTA");
	}
	Engine getType() override
	{
		return TOYOTA;
	}
};

class WiaEngine : public IEngine
{
public:
	std::string getName(void) override
	{
		return std::string("WIA");
	}
	Engine getType() override
	{
		return WIA;
	}
};

class BrokenEngine : public IEngine
{
public:
	std::string getName(void) override
	{
		return std::string("고장난");
	}
	Engine getType() override
	{
		return BROKEN;
	}
};

class EngineFactory
{
public:
	IEngine* getEngine(Engine engine_type)
	{
		IEngine* engine = nullptr;
		switch (engine_type)
		{
		case GM:
			engine = new GmEngine();
			break;
		case TOYOTA:
			engine = new ToyotaEngine();
			break;
		case WIA:
			engine = new WiaEngine;
			break;
		case BROKEN:
			engine = new BrokenEngine();
		default:
			break;
		}

		if (engine != nullptr)
		{
			std::cout << engine->getName() << " 엔진을 선택하셨습니다." << std::endl;
		}
		return engine;
	}
};
