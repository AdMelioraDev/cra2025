
#include "gtest/gtest.h"

#include "Engine.h"

class EngineTest : public ::testing::Test
{
public:
    void SetUp() override {
    }

    void TearDown() override {

    }

    EngineFactory factory;
};

TEST_F(EngineTest, getNameForGmEngine)
{
    IEngine* gm_engine = factory.getEngine(GM);
    EXPECT_EQ(gm_engine->getName(), "GM");
}
