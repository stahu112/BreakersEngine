#pragma once
#include "AssetStorage.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <iostream>
namespace BE
{
	namespace Assets
	{
		enum class Asset
		{
			Texture,
			Font,
			Sound
		};

		class AssetManager
		{
			TextureManager textureManager{};
			FontManager fontManager{};
			void parse(std::string);

		public:
			const sf::Texture& getTexture(std::string en);
			const sf::Font& getFont(std::string en);
			void addAsset(Asset which, std::string name, std::string path);

			AssetManager()
			{
				parse("Assets.xml");
			}
		};

	} //End namespace Assets
} //End namespace BE