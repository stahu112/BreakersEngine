#include "gtest/gtest.h"
#include "../BreakersEngine/Scene.h"

using namespace testing;

namespace BE
{
	class TestState : public SceneState
	{};
	class TestState1 :public SceneState
	{};

}

class TestScene : public Test
{
public:

	BE::Scene scene{ "Scene" };
};

TEST_F(TestScene, SceneHasObjectManagerAndCanPerformActionsOnIt)
{
	scene.objectManager.addObject(new BE::Object);
	scene.objectManager.addObject(new BE::Object);
	scene.objectManager.addObject(new BE::Object);

	ASSERT_EQ(3, scene.objectManager.objectCount());
	ASSERT_TRUE(scene.objectManager.tagTaken("NewObject1"));

	scene.objectManager.destroyObjectByTag("NewObject1");
	ASSERT_EQ(2, scene.objectManager.objectCount());
	ASSERT_FALSE(scene.objectManager.tagTaken("NewObject1"));

	scene.objectManager.destroyAllObjects();
	//ASSERT_EQ(0, scene.objectManager->objectCount());
}

TEST_F(TestScene, SceneHasVirtualInterfaces)
{
	scene.initScene();
	scene.onChangeScene();
}

TEST_F(TestScene, SceneHasValidStateMachine)
{
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "SceneState");
}

TEST_F(TestScene, StateMachinePushThenPopState)
{
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "SceneState");
	ASSERT_EQ(scene.stateMachine.getStackSize(), 1);
	scene.stateMachine.pushState(std::make_unique<BE::TestState>());
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "TestState");
	ASSERT_EQ(scene.stateMachine.getStackSize(), 2);
	scene.stateMachine.popState();
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "SceneState");
	ASSERT_EQ(scene.stateMachine.getStackSize(), 1);
}

TEST_F(TestScene, StateMachineDoesntPopTheInitialState)
{
	ASSERT_THROW(scene.stateMachine.changeState(std::make_unique<BE::SceneState>()), BE::Exceptions::EXTryingToPopInitialState);
}

TEST_F(TestScene, ChangeStateWorks)
{
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "SceneState");
	ASSERT_EQ(scene.stateMachine.getStackSize(), 1);
	scene.stateMachine.pushState(std::make_unique<BE::TestState>());
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "TestState");
	ASSERT_EQ(scene.stateMachine.getStackSize(), 2);
	scene.stateMachine.pushState(std::make_unique<BE::TestState1>());
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "TestState1");
	ASSERT_EQ(scene.stateMachine.getStackSize(), 3);
	scene.stateMachine.changeState(std::make_unique<BE::TestState>());
	ASSERT_EQ(scene.stateMachine.stringifyActiveState(), "TestState");
	ASSERT_EQ(scene.stateMachine.getStackSize(), 3);
}

TEST_F(TestScene, CallUpdate)
{
	for (int i = 0; i < 100; i++)
	{
		scene.stateMachine.getActiveState()->update();
	}
}

TEST_F(TestScene, CallStateMachineParentScene)
{
	std::cout << scene.stateMachine.parentScene->getTag();
}