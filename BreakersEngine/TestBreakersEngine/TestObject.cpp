#include "gtest/gtest.h"
#include "../BreakersEngine/Object.h"

using namespace testing;

class TestObject : public Test
{

public:
	BE::Object obj{ "TEST" };
};

TEST_F(TestObject, GetTag)
{
	ASSERT_EQ(obj.getTag(), "TEST");
}
