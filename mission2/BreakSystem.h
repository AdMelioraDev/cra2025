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
	std::string getName(void) override;
	brakeSystem getType(void) override;
};

class ContinentalBreak : public IBreakSystem
{
public:
	std::string getName(void) override;
	brakeSystem getType(void) override;
};

class BoschBreak : public IBreakSystem
{
public:
	std::string getName(void) override;
	brakeSystem getType(void) override;
};

class BreakSystemFactory
{
public:
	IBreakSystem* getBreakSystem(brakeSystem engine_type);
};
