#include <gtest\gtest.h>
#include "../BreakersEngine/ObjectTransform.h"

using namespace testing;

class TestTransform : public Test
{
public:
	BE::Transform t{};
};

TEST_F(TestTransform, TestBasicVectors)
{
	ASSERT_EQ(sf::Vector2f(0, 0), t.zero());
	ASSERT_EQ(sf::Vector2f(1, 0), t.right());
	ASSERT_EQ(sf::Vector2f(-1, 0), t.left());
	ASSERT_EQ(sf::Vector2f(0, 1), t.down());
	ASSERT_EQ(sf::Vector2f(0, -1), t.up());
}
