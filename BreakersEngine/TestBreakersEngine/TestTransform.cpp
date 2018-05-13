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

TEST_F(TestTransform, RotatateWorkProperly)
{

	t.setRotation(50);
	ASSERT_EQ(t.getRotation(), 50);

	auto rot = t.getRotation();
	t.rotate(90);
	ASSERT_EQ(t.getRotation(), rot + 90);
}

TEST_F(TestTransform, TranslateWorkProperly)
{

	t.setPosition(sf::Vector2f(100, 100));
	ASSERT_EQ(t.getPosition(), sf::Vector2f(100, 100));

	auto pos = t.getPosition();
	t.translate(sf::Vector2f(10, 10));
	ASSERT_EQ(t.getPosition(), pos + sf::Vector2f(10, 10));
}

TEST_F(TestTransform, ScaleWorkProperly)
{
	t.setScale(sf::Vector2f(2, 0.5));
	ASSERT_EQ(t.getScale(), sf::Vector2f(2, 0.5));

	auto scale = t.getScale();
	t.setScale(sf::Vector2f(0.5, 2));
	ASSERT_EQ(t.getScale(), sf::Vector2f(0.5, 2));
}