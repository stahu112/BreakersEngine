#include "Settings.h"
#include <iostream>
namespace BE {

	namespace System {

		std::string Settings::stringify()
		{
			std::string ret;

			ret += std::to_string(windowSettings.width) + "x" + std::to_string(windowSettings.height);

			windowSettings.fullscreen ? ret += " | Fullscreen" : ret += "";

			return ret;
		}

		Settings::Settings(WindowSettings win)
		{
			windowSettings = win;
		}


		Settings::~Settings()
		{
		}
	}
}