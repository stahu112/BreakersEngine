#pragma once

#include <iostream>
#include <stack>
#include "Settings.h"
#include "Window.h"

namespace BE
{
	namespace System
	{
		class Application
		{
			std::unique_ptr<Window> window;
			Settings settings{};

		public:
			
			void run();

			Settings getSettings() const { return settings; }

			void test()
			{
				settings.renderSettings.clearColor = sf::Color::Green;
				settings.windowSettings.setWindowSettings(1920, 1080, true);
				settings.renderSettings.fpsLimit = 0;
				settings.renderSettings.verticalSync = 1;
				std::cout << settings.stringify() << std::endl;
			}

			Application();
			~Application();
		
		};
	
	} //End namespace System
} //End namespace BE