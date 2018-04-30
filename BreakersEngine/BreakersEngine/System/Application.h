#pragma once

#include <iostream>
#include "../ObjectManager.h"
#include "Settings.h"
#include "../Logger.h"
#include "../GUI/Window.h"
#include "Time.h"
#include <thread>
#include "../Scene.h"

namespace BE
{
	namespace System
	{

		class SceneManager
		{
			std::map<std::string, Scene*> sceneMap;

			Scene* currentScene;

		public:
			SceneManager(Scene* scn) : currentScene(scn) {
				//std::make_pair(scn.getTag)
			}

		};

		class Application
		{
			std::unique_ptr<Window> window;
			Settings settings{};

			bool running{ false };

		public:
			Application(Application const&) = delete;
			void operator=(Application const&) = delete;

			static Application * get() {
				static Application instance;
				return &instance;
			}

			void run();
			void exit();

			Settings getSettings() { return settings; }

			Application();
			~Application() { Logger::log(); }

		};

	} //End namespace System
} //End namespace BE