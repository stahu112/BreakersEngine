#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Exceptions.h"
#include <map>
#include <iostream>

namespace BE
{
	namespace Assets
	{
		template <typename T>
		class AssetObjectInterface
		{
		protected:
			std::map<std::string, T> resMap;

		public:

			virtual void addAsset(std::string en, std::string path) = 0;
			virtual void deleteContents() { resMap.clear(); }
			void checkIfExist(std::string name)
			{
				for (auto it = resMap.begin(); it != resMap.end(); it++)
				{
					if (it->first == name)
						throw Exceptions::EXAssetAlreadyExists{};
				}
			}
			unsigned int count() { return resMap.size(); }
			const T& get(std::string en)
			{
				if (resMap.find(en) != resMap.end())
					return resMap.at(en);
				else
					throw Exceptions::EXNoAsset{};

			}
		};

		class TextureManager : public AssetObjectInterface<sf::Texture>
		{
		public:
			void addAsset(std::string en, std::string path) override final
			{
				checkIfExist(en);
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

		class FontManager : public AssetObjectInterface<sf::Font>
		{
		public:
			void addAsset(std::string en, std::string path) override final
			{
				checkIfExist(en);
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

		class SoundManager : public AssetObjectInterface<sf::SoundBuffer>
		{
		public:
			void addAsset(std::string en, std::string path) override final
			{
				checkIfExist(en);
				sf::SoundBuffer sound;
				if (sound.loadFromFile(path))
				{
					resMap.insert(std::make_pair(en, sound));
				}
				else
				{
					std::cout << "WADW" << std::endl;
					throw Exceptions::EXWrongPath{};
				}
			}
		};

	} //End namespace Assets
} //End namespace BE