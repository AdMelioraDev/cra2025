
#include "gtest/gtest.h"

#include "Car.h"
#include "EngineMock.h"
#include "SteeringMock.h"
#include "BrakeSystemMock.h"

class CarTest : public ::testing::Test
{
public:
    void SetUp() override {
    }

    void TearDown() override {

    }

    CarFactory factory;
};

TEST_F(CarTest, getNameForSedan)
{
    ICar* car = factory.getCar(SEDAN);
    EXPECT_EQ(car->getName(), "Sedan");
}

TEST_F(CarTest, isEngineBrokenForSedanFalse)
{
    ICar* car = factory.getCar(SEDAN);
    EngineMock engine_mock;

    car->addEngine(&engine_mock);

    EXPECT_CALL(engine_mock, getType).Times(1).WillOnce(::testing::Return(GM));

    EXPECT_EQ(car->isEngineBroken(), false);
}

TEST_F(CarTest, isValidCheckForSedanReturnTrue)
{
    ICar* car = factory.getCar(SEDAN);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(brake_mock, getType).Times(2).WillRepeatedly(testing::Return(BOSCH_B));
    EXPECT_CALL(steering_mock, getType).Times(1).WillOnce(testing::Return(BOSCH_S));

    EXPECT_EQ(car->isValidCheck(), true);
}

TEST_F(CarTest, isValidCheckForSedanReturnFalseForContinentalBrake)
{
    ICar* car = factory.getCar(SEDAN);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(brake_mock, getType).Times(1).WillOnce(testing::Return(CONTINENTAL));

    EXPECT_EQ(car->isValidCheck(), false);
}

TEST_F(CarTest, isValidCheckForSedanReturnFalseForBoschUnmatch)
{
    ICar* car = factory.getCar(SEDAN);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(brake_mock, getType).Times(2).WillRepeatedly(testing::Return(BOSCH_B));
    EXPECT_CALL(steering_mock, getType).Times(1).WillOnce(testing::Return(MOBIS));

    EXPECT_EQ(car->isValidCheck(), false);
}

TEST_F(CarTest, PrintTestForSedan)
{
    ICar* car = factory.getCar(SEDAN);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(engine_mock, getName).Times(1).WillOnce(testing::Return("GM"));
    EXPECT_CALL(brake_mock, getName).Times(1).WillOnce(testing::Return("MANDO"));
    EXPECT_CALL(steering_mock, getName).Times(1).WillOnce(testing::Return("MOBIS"));

    car->print();

    EXPECT_EQ(1, 1);
}

TEST_F(CarTest, getNameForSuv)
{
    ICar* car = factory.getCar(SUV);
    EXPECT_EQ(car->getName(), "SUV");
}

TEST_F(CarTest, isEngineBrokenForSuvrue)
{
    ICar* car = factory.getCar(SUV);
    EngineMock engine_mock;

    car->addEngine(&engine_mock);

    EXPECT_CALL(engine_mock, getType).Times(1).WillOnce(::testing::Return(BROKEN));

    EXPECT_EQ(car->isEngineBroken(), true);
}

TEST_F(CarTest, isValidCheckForSuvReturnTrue)
{
    ICar* car = factory.getCar(SUV);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(engine_mock, getType).Times(1).WillOnce(testing::Return(GM));
    EXPECT_CALL(brake_mock, getType).Times(1).WillOnce(testing::Return(BOSCH_B));
    EXPECT_CALL(steering_mock, getType).Times(1).WillOnce(testing::Return(BOSCH_S));

    EXPECT_EQ(car->isValidCheck(), true);
}

TEST_F(CarTest, isValidCheckForSuvReturnFalseForToyota)
{
    ICar* car = factory.getCar(SUV);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(engine_mock, getType).Times(1).WillOnce(testing::Return(TOYOTA));

    EXPECT_EQ(car->isValidCheck(), false);
}

TEST_F(CarTest, isValidCheckForSuvReturnFalseForUnmatch)
{
    ICar* car = factory.getCar(SUV);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(engine_mock, getType).Times(1).WillOnce(testing::Return(GM));
    EXPECT_CALL(brake_mock, getType).Times(1).WillOnce(testing::Return(BOSCH_B));
    EXPECT_CALL(steering_mock, getType).Times(1).WillOnce(testing::Return(MOBIS));

    EXPECT_EQ(car->isValidCheck(), false);
}

TEST_F(CarTest, PrintTestForSuv)
{
    ICar* car = factory.getCar(SUV);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(engine_mock, getName).Times(1).WillOnce(testing::Return("GM"));
    EXPECT_CALL(brake_mock, getName).Times(1).WillOnce(testing::Return("MANDO"));
    EXPECT_CALL(steering_mock, getName).Times(1).WillOnce(testing::Return("MOBIS"));

    car->print();

    EXPECT_EQ(1, 1);
}

TEST_F(CarTest, getNameForTruck)
{
    ICar* car = factory.getCar(TRUCK);
    EXPECT_EQ(car->getName(), "Truck");
}

TEST_F(CarTest, isEngineBrokenForTruckTrue)
{
    ICar* car = factory.getCar(TRUCK);
    EngineMock engine_mock;

    car->addEngine(&engine_mock);

    EXPECT_CALL(engine_mock, getType).Times(1).WillOnce(::testing::Return(BROKEN));

    EXPECT_EQ(car->isEngineBroken(), true);
}

TEST_F(CarTest, isValidCheckForTruckReturnFalseForUnmatch)
{
    ICar* car = factory.getCar(TRUCK);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(engine_mock, getType).Times(1).WillOnce(testing::Return(GM));
    EXPECT_CALL(brake_mock, getType).Times(2).WillRepeatedly(testing::Return(BOSCH_B));
    EXPECT_CALL(steering_mock, getType).Times(1).WillOnce(testing::Return(MOBIS));

    EXPECT_EQ(car->isValidCheck(), false);
}

TEST_F(CarTest, PrintTestForTruck)
{
    ICar* car = factory.getCar(TRUCK);
    EngineMock engine_mock;
    BrakeSysteMock brake_mock;
    SteeringMock steering_mock;

    car->addEngine(&engine_mock);
    car->addBreakSystem(&brake_mock);
    car->addSteering(&steering_mock);

    EXPECT_CALL(engine_mock, getName).Times(1).WillOnce(testing::Return("GM"));
    EXPECT_CALL(brake_mock, getName).Times(1).WillOnce(testing::Return("MANDO"));
    EXPECT_CALL(steering_mock, getName).Times(1).WillOnce(testing::Return("MOBIS"));

    car->print();

    EXPECT_EQ(1, 1);
}