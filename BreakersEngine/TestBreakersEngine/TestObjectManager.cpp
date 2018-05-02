#include "gtest/gtest.h"
#include "../BreakersEngine/ObjectManager.h"

using namespace testing;
using namespace BE;

class TestObjectManager : public Test
{
public:
	ObjectManager objectManager{ "TestManager" };

};

TEST_F(TestObjectManager, AddAndDestroyAllObjectsTest)
{
	ASSERT_EQ(objectManager.objectCount(), 0);
	objectManager.addObject(new Object{ "Dupa" });
	objectManager.addObject(new Object{ "Dupa" });
	objectManager.addObject(new Object{ "DupaBlada" });
	ASSERT_EQ(objectManager.objectCount(), 3);

	//objectManager.destroyAllObjects();
}

TEST_F(TestObjectManager, TestDestroyObjectByTag)
{
	ASSERT_EQ(objectManager.objectCount(), 0);
	objectManager.addObject(new Object);
	objectManager.addObject(new Object);
	ASSERT_EQ(objectManager.objectCount(), 2);

	objectManager.destroyObjectByTag("NewObject");
	ASSERT_EQ(objectManager.objectCount(), 1);

	ASSERT_NE(nullptr, objectManager.getObjectByTag("NewObject1"));
}

TEST_F(TestObjectManager, AddThenGetObjectTest)
{
	objectManager.addObject(new Object);
	auto ptr = objectManager.getObjectByTag("NewObject");

	ASSERT_NE(ptr, nullptr);

}

TEST_F(TestObjectManager, AddObjectWithTheSameTag)
{
	for (int i = 0; i < 100; i++)
		objectManager.addObject(new Object);
}

TEST_F(TestObjectManager, CanUseObjectsVirtualFunctions)
{
	for (int i = 0; i < 10; i++)
		objectManager.addObject(new Object);

	objectManager.callUpdate();
	objectManager.callLateUpdate();
}

TEST_F(TestObjectManager, TryGettingObjectThatDoesntExist)
{
	ASSERT_THROW(objectManager.getObjectByTag("NotHere")->getTag(), Exceptions::EXObjectWithTagNotFound);
}