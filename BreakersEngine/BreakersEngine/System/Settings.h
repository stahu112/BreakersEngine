#pragma once

#include <string>
#include "SettingsTypes.h"

namespace BE
{
	namespace System
	{

		/*!
		 * @brief Wrapper class for all the system settings types
		 *
		 */
		class Settings
		{
		public:

			/*!
			* @brief Constructs new Settings instance with all the default settings
			*
			*/
			Settings(WindowSettings winSet = WindowSettings{}, RenderSettings ren = RenderSettings{});
			~Settings();

			WindowSettings windowSettings{};
			RenderSettings renderSettings{};

			std::string stringify();
		};

	} //End namespace System
} //End namespace BE
