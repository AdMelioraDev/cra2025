
#include "gtest/gtest.h"

#include "Car.h"

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
