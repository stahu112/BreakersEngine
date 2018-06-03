#include "Parser.h"
#include "AssetManager.h"
#include "System\Settings.h"

namespace BE
{
	System::Settings SettingsParser::parse()
	{
		// TODO: insert return statement here

		System::Settings set{};
		return set;
	}

	Assets::AssetManager AssetParser::parse()
	{
		Assets::AssetManager am{};
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
					am.addAsset(Assets::Type::Texture, name, path);
				}
				else if (cname == "Font")
				{
					pugi::xml_attribute attr = child.first_attribute();
					std::string name = attr.value();
					attr = attr.next_attribute();
					std::string path = attr.value();
					am.addAsset(Assets::Type::Font, name, path);
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
		return am;
	}
}