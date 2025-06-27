

#include <string>
#include <iostream>

#include "BreakSystem.h"

std::string MandoBreak::getName(void)
{
	return std::string("MANDO");
}
brakeSystem MandoBreak::getType(void)
{
	return MANDO;
}

std::string ContinentalBreak::getName(void)
{
	return std::string("CONTINENTAL");
}
brakeSystem ContinentalBreak::getType(void)
{
	return CONTINENTAL;
}

std::string BoschBreak::getName(void)
{
	return std::string("BOSCH");
}
brakeSystem BoschBreak::getType(void)
{
	return BOSCH_B;
}

IBreakSystem* BreakSystemFactory::getBreakSystem(brakeSystem engine_type)
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
