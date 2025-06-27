
#include "gtest/gtest.h"

#include "BreakSystem.h"

class BrakeTest : public ::testing::Test
{
public:
    void SetUp() override {
    }

    void TearDown() override {

    }

    BreakSystemFactory factory;
};

TEST_F(BrakeTest, getNameForMando)
{
    IBreakSystem* brake = factory.getBreakSystem(MANDO);
    EXPECT_EQ(brake->getName(), "MANDO");
}

TEST_F(BrakeTest, getTypeForMando)
{
    IBreakSystem* brake = factory.getBreakSystem(MANDO);
    EXPECT_EQ(brake->getType(), MANDO);
}

TEST_F(BrakeTest, getNameForContinental)
{
    IBreakSystem* brake = factory.getBreakSystem(CONTINENTAL);
    EXPECT_EQ(brake->getName(), "CONTINENTAL");
}

TEST_F(BrakeTest, getTypeForContinental)
{
    IBreakSystem* brake = factory.getBreakSystem(CONTINENTAL);
    EXPECT_EQ(brake->getType(), CONTINENTAL);
}

TEST_F(BrakeTest, getNameForBosch)
{
    IBreakSystem* brake = factory.getBreakSystem(BOSCH_B);
    EXPECT_EQ(brake->getName(), "BOSCH");
}

TEST_F(BrakeTest, getTypeForBosch)
{
    IBreakSystem* brake = factory.getBreakSystem(BOSCH_B);
    EXPECT_EQ(brake->getType(), BOSCH_B);
}

