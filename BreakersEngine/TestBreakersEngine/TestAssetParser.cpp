#include "gtest\gtest.h"
#include "../BreakersEngine/AssetParser.h"

using namespace testing;

class TestAssetParser : public Test
{
public:
	BE::Assets::AssetParser par{};
};

TEST_F(TestAssetParser, BriefTesting)
{
	par.parse("Assets.xml");
}