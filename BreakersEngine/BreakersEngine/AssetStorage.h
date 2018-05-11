#pragma once
#include <SFML\Graphics.hpp>
#include "Exceptions.h"
#include <map>


namespace BE
{
	namespace Assets
	{
		enum class Texture
		{
			dummyTexture = 0,
			TEXTURE_COUNT
		};
		enum class Font
		{
			dummyFont = 0,
			FONT_COUNT
		};

		template <typename Enum, typename T>
		class AssetObjectInterface
		{
		protected:
			std::map<Enum, T> resMap;

		public:

			virtual void addAsset(Enum en, std::string path) = 0;
			virtual void deleteContents() { resMap.clear(); }
			unsigned int count() { return resMap.size(); }
			const T& get(Enum en)
			{
				if (resMap.find(en) != resMap.end())
					return resMap.at(en);
				else
					throw Exceptions::EXNoAsset{};

			}
		};

		class TextureManager : public AssetObjectInterface<Texture, sf::Texture>
		{
		public:
			void addAsset(Texture en, std::string path) override final
			{
				sf::Texture tex;
				if (tex.loadFromFile(path))
				{
					resMap.insert(std::make_pair(en, tex));
				}
				else
				{
					throw Exceptions::EXWrongPath{};
				}
			}
		};

		class FontManager : public AssetObjectInterface<Font, sf::Font>
		{
		public:
			void addAsset(Font en, std::string path) override final
			{
				sf::Font font;
				if (font.loadFromFile(path))
				{
					resMap.insert(std::make_pair(en, font));
				}
				else
				{
					throw Exceptions::EXWrongPath{};
				}
			}
		};

	} //End namespace Assets
} //End namespace BE