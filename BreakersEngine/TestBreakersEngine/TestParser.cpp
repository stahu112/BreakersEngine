#include "gtest\gtest.h"
#include "../BreakersEngine/Parser.h"
#include "../BreakersEngine/System/Settings.h"
#include "../BreakersEngine/AssetManager.h"

using namespace testing;

class TestParser : public Test
{
public:
	BE::System::Settings set;
	BE::Assets::AssetManager am;
};

TEST_F(TestParser, TestAssetParsingXML)
{
	ASSERT_THROW(am.getTexture("Aoyama"), BE::Exceptions::EXNoAsset);

	BE::AssetParser par{};
	am = par.parse();

	ASSERT_NO_THROW(am.getTexture("Aoyama"), BE::Exceptions::EXNoAsset);
}

TEST_F(TestParser, TestParseSettingsXML)
{
	BE::SettingsParser parser{};
	set = parser.parse();

	ASSERT_FALSE(set.windowSettings.fullscreen);
	ASSERT_EQ(set.windowSettings.height, 300);
	ASSERT_EQ(set.windowSettings.width, 30);
	ASSERT_EQ(set.renderSettings.fpsLimit, 1337);
}