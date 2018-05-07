#include "gtest/gtest.h"
#include "../BreakersEngine/SceneManager.h"

using namespace testing;

class TestSceneManager : public Test
{
public:
	BE::SceneManager sm{ };
};

TEST_F(TestSceneManager, CheckIfManagerHasPlaceHolderScene)
{
	ASSERT_EQ("PlaceHolderScene", sm.currentScene->getTag());
}

TEST_F(TestSceneManager, TestAddScene)
{
	ASSERT_EQ(sm.getSceneCount(), 1);
	for (int i = 0; i < 10; i++)
	{
		sm.addScene(std::make_unique<BE::Scene>("TestScene" + std::to_string(i)));
	}

	ASSERT_EQ(sm.getSceneCount(), 11);
}

TEST_F(TestSceneManager, TestChangeScene)
{
	sm.addScene(std::make_unique<BE::Scene>("TestScene"));


	ASSERT_EQ(sm.currentScene->getTag(), "PlaceHolderScene");
	ASSERT_NO_THROW(sm.changeScene("TestScene"));
	ASSERT_EQ(sm.currentScene->getTag(), "TestScene");
	ASSERT_NO_THROW(sm.changeScene("PlaceHolderScene"));
	ASSERT_EQ(sm.currentScene->getTag(), "PlaceHolderScene");

}

TEST_F(TestSceneManager, TestChangeSceneThatDoesntExist)
{
	ASSERT_THROW(sm.changeScene("TestScene"), BE::Exceptions::EXSceneWithNameNotFound);
}

TEST_F(TestSceneManager, TestStateMachineAfterChangingScenes)
{
	std::cout << sm.currentScene->stateMachine.parentScene->getTag() << std::endl;
	sm.addScene(std::make_unique<BE::Scene>("TestScene"));
	sm.changeScene("TestScene");
	std::cout << sm.currentScene->stateMachine.parentScene->getTag() << std::endl;

}