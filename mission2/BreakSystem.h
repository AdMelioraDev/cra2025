#pragma once

#include <string>
#include <iostream>

enum brakeSystem
{
	MANDO = 1,
	CONTINENTAL,
	BOSCH_B
};

class IBreakSystem
{
public:
	virtual std::string getName() = 0;
	virtual brakeSystem getType() = 0;
};

class MandoBreak : public IBreakSystem
{
public:
	std::string getName(void) override
	{
		return std::string("MANDO");
	}
	brakeSystem getType(void) override
	{
		return MANDO;
	}
};

class ContinentalBreak : public IBreakSystem
{
public:
	std::string getName(void) override
	{
		return std::string("CONTINENTAL");
	}
	brakeSystem getType(void) override
	{
		return CONTINENTAL;
	}
};

class BoschBreak : public IBreakSystem
{
public:
	std::string getName(void) override
	{
		return std::string("BOSCH");
	}
	brakeSystem getType(void) override
	{
		return BOSCH_B;
	}
};

class BreakSystemFactory
{
public:
	IBreakSystem* getBreakSystem(brakeSystem engine_type)
	{
		IBreakSystem* break_system = nullptr;
		switch (engine_type)
		{
		case MANDO:
			break_system = new MandoBreak();
			break;
		case CONTINENTAL:
			break_system = new ContinentalBreak();
			break;
		case BOSCH_B:
			break_system = new BoschBreak;
			break;
		default:
			break;
		}

		if (break_system != nullptr)
		{
			std::cout << break_system->getName() << " 제동장치를 선택하셨습니다." << std::endl;
		}
		return break_system;
	}
};
