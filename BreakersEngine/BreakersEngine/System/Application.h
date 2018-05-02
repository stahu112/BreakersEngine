#pragma once

#include <iostream>
#include "../ObjectManager.h"
#include "Settings.h"
#include "../Logger.h"
#include "../GUI/Window.h"
#include "Time.h"
#include <thread>
#include "../SceneManager.h"

namespace BE
{
	namespace System
	{

		class Application
		{
			std::unique_ptr<Window> window;
			Settings settings{};

			//TODO Make a struture with app specific settings
			bool running{ false };

		public:
			//Delete coput constr. and assign operator
			Application(Application const&) = delete;
			void operator=(Application const&) = delete;

			static Application * get() {
				static Application instance;
				return &instance;
			}

			void run();
			void exit();

			SceneManager sceneManager{};

			Settings getSettings() { return settings; }

			Application();
			~Application() { Logger::log(); }

		};

	} //End namespace System
} //End namespace BE