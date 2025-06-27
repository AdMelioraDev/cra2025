#pragma once

#include <string>
#include <iostream>

#include "gmock/gmock.h"
#include "Steering.h"

class SteeringMock : public ISteering
{
public:
	MOCK_METHOD(std::string, getName, (), (override));
	MOCK_METHOD(SteeringSystem, getType, (), (override));
};
