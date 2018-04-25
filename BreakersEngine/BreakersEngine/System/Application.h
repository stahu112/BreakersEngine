#pragma once

#include <iostream>
#include "../ObjectManager.h"
#include "Settings.h"
#include "../Logger.h"
#include "../GUI/Window.h"
#include "Time.h"
#include <thread>

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

			Settings getSettings() { return settings; }

			Application();
			~Application() { ObjectManager::get().destroyAllObjects(); Logger::log(); }

		};

	} //End namespace System
} //End namespace BE