
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

TEST_F(EngineTest, getTypeForGmEngine)
{
    IEngine* gm_engine = factory.getEngine(GM);
    EXPECT_EQ(gm_engine->getType(), GM);
}

TEST_F(EngineTest, getNameForToyota)
{
    IEngine* gm_engine = factory.getEngine(TOYOTA);
    EXPECT_EQ(gm_engine->getName(), "TOYOTA");
}

TEST_F(EngineTest, getTypeForToyota)
{
    IEngine* gm_engine = factory.getEngine(TOYOTA);
    EXPECT_EQ(gm_engine->getType(), TOYOTA);
}

TEST_F(EngineTest, getNameForWia)
{
    IEngine* gm_engine = factory.getEngine(WIA);
    EXPECT_EQ(gm_engine->getName(), "WIA");
}

TEST_F(EngineTest, getTypeForWia)
{
    IEngine* gm_engine = factory.getEngine(WIA);
    EXPECT_EQ(gm_engine->getType(), WIA);
}

TEST_F(EngineTest, getNameForBroken)
{
    IEngine* gm_engine = factory.getEngine(BROKEN);
    EXPECT_EQ(gm_engine->getName(), "°íÀå³­");
}

TEST_F(EngineTest, getTypeForBroken)
{
    IEngine* gm_engine = factory.getEngine(BROKEN);
    EXPECT_EQ(gm_engine->getType(), BROKEN);
}