#pragma once
#include "AssetStorage.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <iostream>
namespace BE
{
	namespace Assets
	{
		enum class Type
		{
			Texture,
			Font,
			Sound
		};

		class AssetManager
		{
			TextureManager textureManager{};
			FontManager fontManager{};
			SoundManager soundManager{};

		public:
			const sf::Texture& getTexture(std::string en);
			const sf::Font& getFont(std::string en);
			const sf::SoundBuffer& getSound(std::string en);
			void addAsset(Type which, std::string name, std::string path);

		};

	} //End namespace Assets
} //End namespace BE