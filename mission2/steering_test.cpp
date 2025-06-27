
#include "gtest/gtest.h"

#include "Steering.h"

class SteeringTest : public ::testing::Test
{
public:
    void SetUp() override {
    }

    void TearDown() override {

    }

    SteeringFactory factory;
};

TEST_F(SteeringTest, getNameForBosch)
{
    ISteering* bosch = factory.getSteering(BOSCH_S);
    EXPECT_EQ(bosch->getName(), "BOSCH");
}
