#include <gtest\gtest.h>
#include "../BreakersEngine/AssetManager.h"
#include "../BreakersEngine/Parser.h"

using namespace testing;
class TestAssetManager : public Test
{
public:
	BE::Assets::AssetManager am;
	TestAssetManager()
	{
		BE::AssetParser par;
		am = par.parse();
	}
};

TEST_F(TestAssetManager, TestGetAsset)
{
	sf::Texture tex;
	ASSERT_NO_THROW(tex = am.getTexture("Aoyama"));
}

TEST_F(TestAssetManager, TestGetNonExistentAsset)
{
	sf::Texture tex;
	ASSERT_THROW(tex = am.getTexture("NoTex"), BE::Exceptions::EXNoAsset);
}