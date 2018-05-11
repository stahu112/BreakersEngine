#pragma once
#include "AssetStorage.h"
#include "Logger.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <boost\preprocessor.hpp>
#include <map>

namespace BE
{
	namespace Assets
	{
		class AssetManager
		{
			TextureManager textureManager{};
			FontManager fontManager{};

		public:
			const sf::Texture& getTexture(Texture en);
			const sf::Font& getFont(Font en);
			AssetManager();
		};

	} //End namespace Assets
} //End namespace BE