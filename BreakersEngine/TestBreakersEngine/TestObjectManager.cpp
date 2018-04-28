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
	objectManager.addObject(new Object);
	objectManager.addObject(new Object);
	objectManager.addObject(new Object);
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
	Object* ptr = objectManager.getObjectByTag("NewObject");

	ASSERT_NE(ptr, nullptr);

}

TEST_F(TestObjectManager, AddObjectWithTheSameTag)
{
	objectManager.addObject(new Object);
	objectManager.addObject(new Object);
	objectManager.addObject(new Object);
	objectManager.addObject(new Object);
	objectManager.addObject(new Object);

	auto itStart = objectManager.it_begin();

	auto itEnd = objectManager.it_end();

	while (itStart != itEnd)
	{
		std::string buf = itStart->first;
		Logger::log(itStart->first);
		itStart++;
		ASSERT_NE(itStart->first, buf);
	}
}
