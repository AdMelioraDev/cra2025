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
	CarType getType(void) override;;
	std::string getName() override;;
	void addEngine(IEngine* engine) override;;
	void addBreakSystem(IBreakSystem* break_system) override;;
	void addSteering(ISteering* steering) override;;
	bool isValidCheck() override;;
	bool isEngineBroken() override;;
	void print() override;;
	void test() override;;

private:
	CarType _type{ SEDAN };
	IEngine* _engine{ nullptr };
	IBreakSystem* _break{ nullptr };
	ISteering* _steering{ nullptr };
};

class Suv : public ICar
{
public:
	std::string getName() override;
	CarType getType(void) override;
	void addEngine(IEngine* engine) override;
	void addBreakSystem(IBreakSystem* break_system) override;
	void addSteering(ISteering* steering) override;
	bool isValidCheck() override;
	bool isEngineBroken() override;
	void print() override;
	void test() override;

private:
	CarType _type{ SUV };
	IEngine* _engine{ nullptr };
	IBreakSystem* _break{ nullptr };
	ISteering* _steering{ nullptr };
};

class Truck : public ICar
{
public:
	std::string getName() override;
	CarType getType(void) override;
	void addEngine(IEngine* engine) override;
	void addBreakSystem(IBreakSystem* break_system) override;
	void addSteering(ISteering* steering) override;
	bool isValidCheck() override;
	bool isEngineBroken() override;
	void print() override;
	void test() override;

private:
	CarType _type{ TRUCK };
	IEngine* _engine{ nullptr };
	IBreakSystem* _break{ nullptr };
	ISteering* _steering{ nullptr };
};


class CarFactory
{
public:
	ICar* getCar(CarType engine_type);
};
