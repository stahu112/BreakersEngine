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

TEST_F(TestTransform, TestChildrenPosition)
{
	t.setPosition({ 0,0 });
	BE::Transform trans{};
	BE::Transform trans1{};
	trans.setPosition({ 10, 10 });
	trans1.setPosition({ 50, 50 });
	t.addChild(trans);
	t.addChild(trans1);
	t.setPosition({ 100,100 });
	ASSERT_EQ(trans.getPosition().x, 110);
	ASSERT_EQ(trans.getPosition().y, 110);
	t.translate({ 50,50 });
	ASSERT_EQ(trans1.getPosition().x, 200);
	ASSERT_EQ(trans1.getPosition().y, 200);
}

TEST_F(TestTransform, TestChildrenRotation)
{
	t.setRotation(0);
	BE::Transform trans{};
	BE::Transform trans1{};
	trans1.setRotation(90);
	trans.setRotation(90);
	t.addChild(trans);
	t.setRotation(90);
	ASSERT_EQ(trans.getRotation(), 180);
	t.addChild(trans1);
	t.rotate(90);
	ASSERT_EQ(trans1.getRotation(), 180);
	ASSERT_EQ(trans.getRotation(), 270);
}