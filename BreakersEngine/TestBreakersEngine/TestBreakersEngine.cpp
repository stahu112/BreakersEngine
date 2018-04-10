#include "gtest/gtest.h"
#include "../BreakersEngine/System/Settings.h"
#include <thread>

TEST(TestSettings, DefaultFpsLimit)
{
	BE::System::Settings set{};

	EXPECT_EQ(60, set.renderSettings.fpsLimit);
}

TEST(TestSettings, DefaultWindowSize)
{
	BE::System::Settings set{};

	EXPECT_EQ(1366, set.windowSettings.width);
	EXPECT_EQ(768, set.windowSettings.height);
}

TEST(TestSettings, DefaultClearColor)
{
	BE::System::Settings set{};

	EXPECT_EQ(sf::Color::White, set.renderSettings.clearColor);
}