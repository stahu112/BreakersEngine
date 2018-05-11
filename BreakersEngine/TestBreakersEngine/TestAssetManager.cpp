#include <gtest\gtest.h>
#include "../BreakersEngine/AssetManager.h"

using namespace testing;

class TestAssetManager : public Test
{
public:
	BE::Assets::AssetManager am{};
};

TEST_F(TestAssetManager, TestConstructor)
{
}

TEST_F(TestAssetManager, TestGetAsset)
{
	sf::Texture tex;
	ASSERT_NO_THROW(tex = am.getTexture(BE::Assets::Texture::dummyTexture));
	BE::Logger::log("Width: " + std::to_string(tex.getSize().x) + " Height: " + std::to_string(tex.getSize().y));
}

TEST_F(TestAssetManager, TestGetNonExistentAsset)
{
	sf::Texture tex;
	ASSERT_THROW(tex = am.getTexture(BE::Assets::Texture::TEXTURE_COUNT), BE::Exceptions::EXNoAsset);
}

/*
* TODO Test the parser
* */
TEST_F(TestAssetManager, TestParse)
{

}