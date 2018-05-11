#include "AssetManager.h"
#include <iostream>
namespace BE
{
	namespace Assets
	{
		const sf::Texture & AssetManager::getTexture(Texture en)
		{
			return textureManager.get(en);
		}
		const sf::Font & AssetManager::getFont(Font en)
		{
			return fontManager.get(en);
		}
		AssetManager::AssetManager()
		{
			textureManager.addAsset(Texture::dummyTexture, "Resources/Textures/aoy.jpg");
			/*
			* TODO Parse File with assets (csv? xml? yaml?)
			* */
		}


	} //End namespace Assets
} //End namespace BE