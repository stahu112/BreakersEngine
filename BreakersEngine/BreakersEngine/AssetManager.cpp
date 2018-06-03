#include "AssetManager.h"
#include <pugixml.hpp>
#include <iostream>
namespace BE
{
	namespace Assets
	{
		const sf::Texture & AssetManager::getTexture(std::string en)
		{
			return textureManager.get(en);
		}
		const sf::Font & AssetManager::getFont(std::string en)
		{
			return fontManager.get(en);
		}
		void AssetManager::addAsset(Type which, std::string name, std::string path)
		{
			switch (which)
			{
			case Type::Texture:
				textureManager.addAsset(name, path);
				break;
			case Type::Font:
				fontManager.addAsset(name, path);
				break;
			}
		}

	} //End namespace Assets
} //End namespace BE