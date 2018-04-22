#include "gtest/gtest.h"
#include "../BreakersEngine/ObjectManager.h"

using namespace testing;
using namespace BE;

class TestObjectManager : public Test
{
public:

};

TEST_F(TestObjectManager, SuccesfullGetInstance)
{
	ObjectManager::get();
}

TEST_F(TestObjectManager, AddAndDestroyAllObjectsTest)
{
	ASSERT_EQ(ObjectManager::get().objectCount(), 0);
	Object obj{};
	ObjectManager::get().addObject(obj);
	ObjectManager::get().addObject(obj);
	ObjectManager::get().addObject(obj);
	ASSERT_EQ(ObjectManager::get().objectCount(), 3);
	ObjectManager::get().destroyAllObjects();

	ASSERT_EQ(ObjectManager::get().objectCount(), 0);
}

TEST_F(TestObjectManager, TestDestroyObjectByTag)
{
	ASSERT_EQ(ObjectManager::get().objectCount(), 0);
	Object obj{};
	ObjectManager::get().addObject(obj);
	ASSERT_EQ(ObjectManager::get().objectCount(), 1);
	ObjectManager::get().destroyObjectByTag("NewObject");
	ASSERT_EQ(ObjectManager::get().objectCount(), 0);
}

TEST_F(TestObjectManager, AddThenGetObjectTest)
{
	Object obj{};
	ObjectManager::get().addObject(obj);
	Object* ptr = ObjectManager::get().getObjectByTag("NewObject");

	ASSERT_NE(ptr, nullptr);
	ObjectManager::get().destroyAllObjects();
}

TEST_F(TestObjectManager, AddObjectWithTheSameTag)
{
	Object obj{};
	ObjectManager::get().addObject(obj);
	ObjectManager::get().addObject(obj);
	ObjectManager::get().addObject(obj);
	ObjectManager::get().addObject(obj);
	ObjectManager::get().addObject(obj);

	auto itStart = ObjectManager::get().it_begin();

	auto itEnd = ObjectManager::get().it_end();

	while (itStart != itEnd)
	{
		std::string buf = itStart->first;
		itStart++;
		ASSERT_NE(itStart->first, buf);
	}
	ObjectManager::get().destroyAllObjects();
}
