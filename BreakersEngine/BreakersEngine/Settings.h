#pragma once

#include <string>
#include "SettingsTypes.h"

namespace BE
{
	namespace System
	{
		class Settings
		{
		public:
			//TODO ParseSettings
			Settings(WindowSettings winSet = WindowSettings{}, RenderSettings ren = RenderSettings{});
			~Settings();

			WindowSettings windowSettings{};
			RenderSettings renderSettings{};

			std::string stringify();
		};

	} //End namespace System
} //End namespace BE