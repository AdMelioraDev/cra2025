
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

TEST_F(SteeringTest, getTypeForBosch)
{
    ISteering* bosch = factory.getSteering(BOSCH_S);
    EXPECT_EQ(bosch->getType(), BOSCH_S);
}

TEST_F(SteeringTest, getNameForMobis)
{
    ISteering* bosch = factory.getSteering(MOBIS);
    EXPECT_EQ(bosch->getName(), "MOBIS");
}

TEST_F(SteeringTest, getTypeForMobis)
{
    ISteering* bosch = factory.getSteering(MOBIS);
    EXPECT_EQ(bosch->getType(), MOBIS);
}