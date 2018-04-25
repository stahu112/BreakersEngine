#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace BE
{
	namespace System
	{
		struct SettingsInterface
		{	
			virtual std::string stringify()
			{
				return "Base stringify";
			}

			std::string genHead(std::string head)
			{
				std::string ret{};
				ret += "\n";
				ret += std::string(head.size() + 10, '-');
				ret += "\n";
				ret += std::string(5, '-');
				ret += head;
				ret += std::string(5, '-');
				ret += "\n";
				ret += std::string(head.size() + 10, '-');
				ret += "\n\n";

				return ret;
			}
			//TODO serializing interface

		};

		//WindowSettings
		struct WindowSettings : public SettingsInterface
		{
			unsigned int width;
			unsigned int height;
			bool fullscreen;

			std::string stringify() override
			{
				std::string ret{};
				ret += genHead("Window Settings");

				ret += "Resolution: " + std::to_string(width) + "x" + std::to_string(height);

				fullscreen ? ret += " | Fullscreen\n" : ret += "\n";

				return ret;
			}

			WindowSettings(unsigned int w = 1366, unsigned int h = 768, bool full = false) :
				width(w), height(h), fullscreen(full) {}
		};

		//RenderSettings
		struct RenderSettings : public SettingsInterface
		{
		
			sf::Color clearColor;
			bool doubleBuffering;
			bool verticalSync;
			unsigned int fpsLimit;

			std::string stringify() override 
			{
				std::string ret{};
				ret += genHead("Render Settings");

				ret += "Clear Color: (" + std::to_string(clearColor.r) + ":" 
					+ std::to_string(clearColor.g) + ":" 
					+ std::to_string(clearColor.b) + ":"
					+ std::to_string(clearColor.a) + ")\n";

				ret += "FPS Limit: " + std::to_string(fpsLimit) + "\n";

				ret += "Double buffering: " + std::to_string(doubleBuffering) + "\n";
				ret += "Vertical sync: " + std::to_string(verticalSync) + "\n";

				return ret;
			}

			RenderSettings(sf::Color col = sf::Color::White, bool db = false, bool vs = true, unsigned int fps = 60) :
				clearColor(col), doubleBuffering(db), verticalSync(vs), fpsLimit(fps) {}
		};

	} //End namespace System
} //End namespace BE