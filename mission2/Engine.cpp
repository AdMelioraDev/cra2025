
#include <string>
#include <iostream>

#include "Engine.h"

std::string GmEngine::getName()
{
	return std::string("GM");
}

Engine GmEngine::getType()
{
	return GM;
}

std::string ToyotaEngine::getName()
{
	return std::string("TOYOTA");
}

Engine ToyotaEngine::getType()
{
	return TOYOTA;
}

std::string WiaEngine::getName()
{
	return std::string("WIA");
}

Engine WiaEngine::getType()
{
	return WIA;
}

std::string BrokenEngine::getName()
{
	return std::string("고장난");
}

Engine BrokenEngine::getType()
{
	return BROKEN;
}


IEngine* EngineFactory::getEngine(Engine engine_type)
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

