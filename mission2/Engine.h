#pragma once

#include <string>
#include <iostream>

enum Engine
{
	GM = 1,
	TOYOTA,
	WIA
};

class IEngine
{
public:
	virtual std::string getName() = 0;
};

class GmEngine : public IEngine
{
public:
	std::string getName(void) override
	{
		return std::string("GM");
	}
};

class ToyotaEngine : public IEngine
{
public:
	std::string getName(void) override
	{
		return std::string("TOYOTA");
	}
};

class WiaEngine : public IEngine
{
public:
	std::string getName(void) override
	{
		return std::string("WIA");
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
