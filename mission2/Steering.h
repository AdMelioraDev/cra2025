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
	virtual SteeringSystem getType() = 0;
};

class BoschSteering : public ISteering
{
public:
	std::string getName(void) override;
	SteeringSystem getType() override;
};

class MobisSteering : public ISteering
{
public:
	std::string getName(void) override;
	SteeringSystem getType() override;
};

class SteeringFactory
{
public:
	ISteering* getSteering(SteeringSystem steering_type);
};
