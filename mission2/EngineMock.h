#pragma once

#include <string>
#include <iostream>

#include "gmock/gmock.h"
#include "Engine.h"

class EngineMock : public IEngine
{
public:
	MOCK_METHOD(std::string, getName, (), (override));
	MOCK_METHOD(Engine, getType, (), (override));
};
