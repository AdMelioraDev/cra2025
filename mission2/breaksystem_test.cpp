
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

TEST_F(BrakeTest, getNameForGmEngine)
{
    IBreakSystem* brake = factory.getBreakSystem(MANDO);
    EXPECT_EQ(brake->getName(), "MANDO");
}
