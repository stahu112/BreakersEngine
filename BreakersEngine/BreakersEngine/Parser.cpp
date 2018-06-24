#include "Parser.h"
#include "AssetManager.h"
#include "System\Settings.h"

namespace BE
{
	System::Settings SettingsParser::parse()
	{
		System::Settings set{};

		if (!doc.load_file(path.data())) throw BE::Exceptions::EXNoConfigFile{};

		pugi::xml_node setGrp = doc.child("Config");

		for (pugi::xml_node grp = setGrp.first_child(); grp; grp = grp.next_sibling())
		{
			for (pugi::xml_node child = grp.first_child(); child; child = child.next_sibling())
			{
				std::string name = child.name();

				if (name == "Width")
					set.windowSettings.width = child.text().as_uint();
				if (name == "Height")
					set.windowSettings.height = child.text().as_uint();
				if (name == "Fullscreen")
					set.windowSettings.fullscreen = child.text().as_bool();
				if (name == "ClearColorR")
					set.renderSettings.clearColor.r = child.text().as_int();
				if (name == "ClearColorG")
					set.renderSettings.clearColor.g = child.text().as_int();
				if (name == "ClearColorB")
					set.renderSettings.clearColor.b = child.text().as_int();
				if (name == "ClearColorA")
					set.renderSettings.clearColor.a = child.text().as_int();
				if (name == "DoubleBuff")
					set.renderSettings.doubleBuffering = child.text().as_bool();
				if (name == "VSync")
					set.renderSettings.verticalSync = child.text().as_bool();
				if (name == "FPSLimit")
					set.renderSettings.fpsLimit = child.text().as_int();
			}
		}

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
					am.addAsset(Assets::Type::Sound, name, path);
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