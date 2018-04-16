#include "gtest/gtest.h"
#include "../BreakersEngine/System/Settings.h"
#include <thread>

using namespace testing;

class TestSettings : public Test
{
public:
	BE::System::Settings set{};

};

TEST_F(TestSettings, DefaultFpsLimit)
{
	ASSERT_EQ(60, set.renderSettings.fpsLimit);
}

TEST_F(TestSettings, DefaultWindowSize)
{
	ASSERT_EQ(1366, set.windowSettings.width);
	ASSERT_EQ(768, set.windowSettings.height);
}

TEST_F(TestSettings, DefaultClearColor)
{
	ASSERT_EQ(sf::Color::White, set.renderSettings.clearColor);
}

TEST_F(TestSettings, TestStringify)
{
	std::cout << set.stringify() << std::endl;
}