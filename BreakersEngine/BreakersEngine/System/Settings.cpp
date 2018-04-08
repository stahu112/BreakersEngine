#include "Settings.h"
#include <iostream>
namespace BE {

	namespace System {

		std::string Settings::stringify()
		{
			std::string ret{};
			ret += "Current settings";
			ret += windowSettings.stringify();
			ret += renderSettings.stringify();

			return ret;
		}

		//TODO parse touple with settings
		Settings::Settings(WindowSettings win, RenderSettings ren)
		{
			windowSettings = win;
			renderSettings = ren;
		}


		Settings::~Settings()
		{
		}
	}
}