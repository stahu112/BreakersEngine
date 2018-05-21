#include "gtest/gtest.h"
#include "../BreakersEngine/System/Application.h"
#include "../BreakersEngine/AssetManager.h"

using namespace testing;
using namespace BE;

class TestApp : public Test
{
public:
};

TEST_F(TestApp, SuccessfullyGetInstance)
{
	ASSERT_NE(System::Application::get(), nullptr);
}
