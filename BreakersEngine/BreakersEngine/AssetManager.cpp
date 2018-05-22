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
		void AssetManager::addAsset(Asset which, std::string name, std::string path)
		{
			switch (which)
			{
			case Asset::Texture:
				textureManager.addAsset(name, path);
				break;
			case Asset::Font:
				fontManager.addAsset(name, path);
				break;
			}
		}

		void AssetManager::parse(std::string path) {
			pugi::xml_document doc;

			if (!doc.load_file(path.data())) throw BE::Exceptions::EXNoConfigFile{};

			pugi::xml_node resGrp = doc.child("ResourceList");

			for (pugi::xml_node grp = resGrp.first_child(); grp; grp = grp.next_sibling())
			{
				for (pugi::xml_node child = grp.first_child(); child; child = child.next_sibling())
				{
					std::string cname = child.name();

					if (cname == "Texture")
					{
						pugi::xml_attribute attr = child.first_attribute();
						std::string name = attr.value();
						attr = attr.next_attribute();
						std::string path = attr.value();
						addAsset(Asset::Texture, name, path);
					}
					else if (cname == "Font")
					{
						pugi::xml_attribute attr = child.first_attribute();
						std::string name = attr.value();
						attr = attr.next_attribute();
						std::string path = attr.value();
						addAsset(Asset::Font, name, path);
					}
					else if (cname == "Sound")
					{
						pugi::xml_attribute attr = child.first_attribute();
						std::string name = attr.value();
						attr = attr.next_attribute();
						std::string path = attr.value();
						//TODO Add sound parse
					}
					else
					{
						throw BE::Exceptions::EXAssetNotValid{};
					}
				}
			}
		}

	} //End namespace Assets
} //End namespace BE