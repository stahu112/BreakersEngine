#include "gtest/gtest.h"
#include "../BreakersEngine/SceneManager.h"

using namespace testing;

class TestSceneManager : public Test
{
public:
	BE::SceneManager sm{ new BE::Scene {"PlaceHolderScene"} };
};

TEST_F(TestSceneManager, CheckIfManagerHasPlaceHolderScene)
{
	ASSERT_NE(nullptr, sm.getCurrentScene());
}

TEST_F(TestSceneManager, TestAddScene)
{
	ASSERT_EQ(sm.getSceneCount(), 1);
	for (int i = 0; i < 10; i++)
	{
		sm.addScene(new BE::Scene{ "TestScene" + std::to_string(i) });
	}

	ASSERT_EQ(sm.getSceneCount(), 11);
}

TEST_F(TestSceneManager, TestChangeScene)
{
	sm.addScene(new BE::Scene{ "TestScene" });

	ASSERT_NO_THROW(sm.changeScene("TestScene"));
	ASSERT_NO_THROW(sm.changeScene("PlaceHolderScene"));
}

TEST_F(TestSceneManager, TestChangeSceneThatDoesntExist)
{
	ASSERT_THROW(sm.changeScene("TestScene"), BE::Exceptions::EXSceneWithNameNotFound);
}

TEST_F(TestSceneManager, Test1)
{

}