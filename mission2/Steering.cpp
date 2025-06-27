
#include <string>
#include <iostream>

#include "Steering.h"

std::string BoschSteering::getName(void)
{
	return std::string("BOSCH");
}
SteeringSystem BoschSteering::getType()
{
	return BOSCH_S;
}

std::string MobisSteering::getName(void)
{
	return std::string("MOBIS");
}
SteeringSystem MobisSteering::getType()
{
	return MOBIS;
}

ISteering* SteeringFactory::getSteering(SteeringSystem steering_type)
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
