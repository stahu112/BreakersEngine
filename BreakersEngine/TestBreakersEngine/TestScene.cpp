#include "gtest/gtest.h"
#include "../BreakersEngine/Scene.h"

using namespace testing;

class TestScene : public Test
{
public:
	BE::Scene scene{ "Scene" };
};

TEST_F(TestScene, SceneHasObjectManagerAndCanPerformActionsOnIt)
{
	scene.objectManager->addObject(new BE::Object);
	scene.objectManager->addObject(new BE::Object);
	scene.objectManager->addObject(new BE::Object);

	ASSERT_EQ(3, scene.objectManager->objectCount());
	ASSERT_TRUE(scene.objectManager->tagTaken("NewObject1"));

	scene.objectManager->destroyObjectByTag("NewObject1");
	ASSERT_EQ(2, scene.objectManager->objectCount());
	ASSERT_FALSE(scene.objectManager->tagTaken("NewObject1"));

	scene.objectManager->destroyAllObjects();
	ASSERT_EQ(0, scene.objectManager->objectCount());
}

TEST_F(TestScene, SceneHasVirtualInterfaces)
{
	scene.initScene();
	scene.onChangeScene();
}