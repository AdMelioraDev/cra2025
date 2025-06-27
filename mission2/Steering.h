#pragma once

#include <string>
#include <iostream>

enum SteeringSystem
{
	BOSCH_S = 1,
	MOBIS
};

class ISteering
{
public:
	virtual std::string getName() = 0;
};

class BoschSteering : public ISteering
{
public:
	std::string getName(void) override
	{
		return std::string("BOSCH");
	}
};

class MobisSteering : public ISteering
{
public:
	std::string getName(void) override
	{
		return std::string("MOBIS");
	}
};

class SteeringFactory
{
public:
	ISteering* getSteering(SteeringSystem steering_type)
	{
		ISteering* steering = nullptr;
		switch (steering_type)
		{
		case BOSCH_S:
			steering = new BoschSteering();
			break;
		case MOBIS:
			steering = new MobisSteering();
			break;
		default:
			break;
		}

		if (steering != nullptr)
		{
			std::cout << steering->getName() << " 조향장치를 선택하셨습니다." << std::endl;
		}
		return steering;
	}
};
