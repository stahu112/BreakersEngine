#include "gtest/gtest.h"
#include "../BreakersEngine/System/Application.h"

using namespace testing;
using namespace BE::System;

class TestApp : public Test
{
public:
};

TEST_F(TestApp, SuccessfullyGetInstance)
{
	Application::get();
}

TEST_F(TestApp, Test1)
{

}
