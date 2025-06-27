#pragma once

#include <string>
#include <iostream>

#include "gmock/gmock.h"
#include "BreakSystem.h"

class BrakeSysteMock : public IBreakSystem
{
public:
	MOCK_METHOD(std::string, getName, (), (override));
	MOCK_METHOD(brakeSystem, getType, (), (override));
};
