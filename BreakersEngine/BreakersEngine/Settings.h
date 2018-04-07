#pragma once

#include <string>

namespace BE
{
	namespace System
	{
		
		struct WindowSettings
		{
			unsigned int width;
			unsigned int height;
			bool fullscreen;

			WindowSettings(unsigned int w = 1920, unsigned int h = 1080, bool full = false) : width(w), height(h), fullscreen(full) {}
			
		};

		class Settings
		{
			WindowSettings windowSettings{};

		public:
			//TODO ParseSettings
			Settings(WindowSettings winSet = WindowSettings{});
			~Settings();
			
			WindowSettings getWindowSettings() const {return windowSettings;}

			std::string stringify();
		};

	} //End namespace System
} //End namespace BE