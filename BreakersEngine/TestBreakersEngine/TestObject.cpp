#include "gtest/gtest.h"
#include "../BreakersEngine/Object.h"

using namespace testing;

class TestObject : public Test
{
public:
	BE::Object obj{};

};

TEST_F(TestObject, CheckDefaultEmptyVirtualInterfacesExist)
{
	obj.fixedUpdate();
	obj.lateUpdate();
	obj.onDestroy();
	obj.update();
	obj.onInit();
}