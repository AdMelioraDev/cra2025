#pragma once

#include <string>
#include <iostream>

#include "Engine.h"
#include "BreakSystem.h"
#include "Steering.h"

enum CarType
{
	SEDAN = 1,
	SUV,
	TRUCK
};

class ICar
{
public:
	virtual CarType getType() = 0;
	virtual std::string getName() = 0;
	virtual void addEngine(IEngine* engine) = 0;
	virtual void addBreakSystem(IBreakSystem* break_system) = 0;
	virtual void addSteering(ISteering* steering) = 0;
	virtual bool isValidCheck() = 0;
	virtual bool isEngineBroken() = 0;
	virtual void print() = 0;
	virtual void test() = 0;
};

class Sedan : public ICar
{
public:
	CarType getType(void) override
	{
		return _type;
	}
	std::string getName() override
	{
		return std::string("Sedan");
	}
	void addEngine(IEngine* engine) override
	{
		_engine = engine;
	}
	void addBreakSystem(IBreakSystem* break_system) override
	{
		_break = break_system;
	}
	void addSteering(ISteering* steering) override
	{
		_steering = steering;
	}
	bool isValidCheck() override
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
	bool isEngineBroken() override
	{
		return (_engine->getType() == BROKEN);
	}
	void print() override
	{
		std::cout << "Car Type : Sedan" << std::endl;
		std::cout << "Engine : " << _engine->getName() << std::endl;
		std::cout << "Brake System : " << _break->getName() << std::endl;
		std::cout << "SteeringSystem : " << _steering->getName() << std::endl;
	}
	void test() override
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

private:
	CarType _type{ SEDAN };
	IEngine* _engine{ nullptr };
	IBreakSystem* _break{ nullptr };
	ISteering* _steering{ nullptr };
};

class Suv : public ICar
{
public:
	std::string getName() override
	{
		return std::string("SUV");
	}
	CarType getType(void) override
	{
		return _type;
	}
	void addEngine(IEngine* engine)
	{
		_engine = engine;
	}
	void addBreakSystem(IBreakSystem* break_system) override
	{
		_break = break_system;
	}
	void addSteering(ISteering* steering) override
	{
		_steering = steering;
	}
	bool isValidCheck() override
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
	bool isEngineBroken() override
	{
		return (_engine->getType() == BROKEN);
	}
	void print() override
	{
		std::cout << "Car Type : SUV" << std::endl;
		std::cout << "Engine : " << _engine->getName() << std::endl;
		std::cout << "Brake System : " << _break->getName() << std::endl;
		std::cout << "SteeringSystem : " << _steering->getName() << std::endl;
	}
	void test() override
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

private:
	CarType _type{ SUV };
	IEngine* _engine{ nullptr };
	IBreakSystem* _break{ nullptr };
	ISteering* _steering{ nullptr };
};

class Truck : public ICar
{
public:
	std::string getName() override
	{
		return std::string("Truck");
	}
	CarType getType(void) override
	{
		return _type;
	}
	void addEngine(IEngine* engine)
	{
		_engine = engine;
	}
	void addBreakSystem(IBreakSystem* break_system) override
	{
		_break = break_system;
	}
	void addSteering(ISteering* steering) override
	{
		_steering = steering;
	}
	bool isValidCheck() override
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
	bool isEngineBroken() override
	{
		return (_engine->getType() == BROKEN);
	}
	void print() override
	{
		std::cout << "Car Type : Truck" << std::endl;
		std::cout << "Engine : " << _engine->getName() << std::endl;
		std::cout << "Brake System : " << _break->getName() << std::endl;
		std::cout << "SteeringSystem : " << _steering->getName() << std::endl;
	}
	void test() override
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

private:
	CarType _type{ TRUCK };
	IEngine* _engine{ nullptr };
	IBreakSystem* _break{ nullptr };
	ISteering* _steering{ nullptr };
};


class CarFactory
{
public:
	ICar* getCar(CarType engine_type)
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
};
