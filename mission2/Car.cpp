#include <string>
#include <iostream>

#include "Car.h"

std::string Sedan::getName()
{
	return std::string("Sedan");
}
void Sedan::addEngine(IEngine* engine)
{
	_engine = engine;
}
void Sedan::addBreakSystem(IBreakSystem* break_system)
{
	_break = break_system;
}
void Sedan::addSteering(ISteering* steering)
{
	_steering = steering;
}
bool Sedan::isValidCheck()
{
	if (_break->getType() == CONTINENTAL)
	{
		return false;
	}
	else if (_break->getType() == BOSCH_B && _steering->getType() != BOSCH_S)
	{
		return false;
	}
	return true;
}
bool Sedan::isEngineBroken()
{
	return (_engine->getType() == BROKEN);
}
void Sedan::print()
{
	std::cout << "Car Type : Sedan" << std::endl;
	std::cout << "Engine : " << _engine->getName() << std::endl;
	std::cout << "Brake System : " << _break->getName() << std::endl;
	std::cout << "SteeringSystem : " << _steering->getName() << std::endl;
}
void Sedan::test()
{
	if (_break->getType() == CONTINENTAL)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Sedan에는 Continental제동장치 사용 불가\n");
	}
	else if (_break->getType() == BOSCH_B && _steering->getType() != BOSCH_S)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
	}
	else
	{
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
}

std::string Suv::getName()
{
	return std::string("SUV");
}
void Suv::addEngine(IEngine* engine)
{
	_engine = engine;
}
void Suv::addBreakSystem(IBreakSystem* break_system)
{
	_break = break_system;
}
void Suv::addSteering(ISteering* steering)
{
	_steering = steering;
}
bool Suv::isValidCheck()
{
	if (_engine->getType() == TOYOTA)
	{
		return false;
	}
	else if (_break->getType() == BOSCH_B && _steering->getType() != BOSCH_S)
	{
		return false;
	}
	return true;
}
bool Suv::isEngineBroken()
{
	return (_engine->getType() == BROKEN);
}
void Suv::print()
{
	std::cout << "Car Type : SUV" << std::endl;
	std::cout << "Engine : " << _engine->getName() << std::endl;
	std::cout << "Brake System : " << _break->getName() << std::endl;
	std::cout << "SteeringSystem : " << _steering->getName() << std::endl;
}
void Suv::test()
{
	if (_engine->getType() == TOYOTA)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("SUV에는 TOYOTA엔진 사용 불가\n");
	}
	else if (_break->getType() == BOSCH_B && _steering->getType() != BOSCH_S)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
	}
	else
	{
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
}


std::string Truck::getName()
{
	return std::string("Truck");
}
void Truck::addEngine(IEngine* engine)
{
	_engine = engine;
}
void Truck::addBreakSystem(IBreakSystem* break_system)
{
	_break = break_system;
}
void Truck::addSteering(ISteering* steering)
{
	_steering = steering;
}
bool Truck::isValidCheck()
{
	if (_engine->getType() == WIA)
	{
		return false;
	}
	else if (_break->getType() == MANDO)
	{
		return false;
	}
	else if (_break->getType() == BOSCH_B && _steering->getType() != BOSCH_S)
	{
		return false;
	}

	return true;
}
bool Truck::isEngineBroken()
{
	return (_engine->getType() == BROKEN);
}
void Truck::print()
{
	std::cout << "Car Type : Truck" << std::endl;
	std::cout << "Engine : " << _engine->getName() << std::endl;
	std::cout << "Brake System : " << _break->getName() << std::endl;
	std::cout << "SteeringSystem : " << _steering->getName() << std::endl;
}
void Truck::test()
{
	if (_engine->getType() == WIA)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Truck에는 WIA엔진 사용 불가\n");
	}
	else if (_break->getType() == MANDO)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Truck에는 Mando제동장치 사용 불가\n");
	}
	else if (_break->getType() == BOSCH_B && _steering->getType() != BOSCH_S)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
	}
	else
	{
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
}


ICar* CarFactory::getCar(CarType engine_type)
{
	ICar* car = nullptr;
	switch (engine_type)
	{
	case GM:
		car = new Sedan();
		break;
	case TOYOTA:
		car = new Suv();
		break;
	case WIA:
		car = new Truck();
		break;
	default:
		break;
	}

	if (car != nullptr)
	{
		std::cout << "차량 타입으로 " << car->getName() << "을 선택하셨습니다." << std::endl;
	}
	return car;
}

