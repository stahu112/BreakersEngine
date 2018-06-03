#pragma once
#include <memory>
#include <pugixml.hpp>

namespace BE
{
	namespace Assets
	{
		class AssetManager;
	}
	namespace System
	{
		class Settings;
	}
	/*!
	 * @brief base class for making xml parsers
	 *
	 */
	class ParserInterface
	{
	protected:
		std::string path;
		pugi::xml_document doc;
	public:
		ParserInterface(std::string filePath = "")
		{
			path = filePath;
		}

		void changePath(std::string newPath)
		{
			path = newPath;
		}
	};

	/*!
	 * @brief Assets parser
	 *
	 */
	class AssetParser : public ParserInterface
	{

	public:

		AssetParser(std::string path = "Assets.xml") : ParserInterface(path) {}

		Assets::AssetManager parse();
	};

	/*!
	 * @brief Configuration file parser
	 *
	 */
	class SettingsParser : public ParserInterface
	{
	public:

		SettingsParser(std::string path = "Settings.xml") :ParserInterface(path) {}
		System::Settings parse();
	};

}