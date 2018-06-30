#pragma once

#include <iostream>
#include <thread>
#include "Settings.h"
#include "../Parser.h"
#include "../AssetManager.h"
#include "../Logger.h"
#include "../GUI/Window.h"
#include "Time.h"
#include <thread>
#include "../SceneManager.h"
#include "../InputManager.h"

#define APP BE::System::Application::get()
#define WINDOW BE::System::Application::get()->window
#define WINDOW_SETTINGS BE::System::Application::get()->window->getSettings().windowSettings
#define RENDER_SETTINGS BE::System::Application::get()->window->getSettings().renderSettings
#define SCENE_MANAGER BE::System::Application::get()->sceneManager
#define ASSET_MANAGER BE::System::Application::get()->assetManager
#define INPUT_MANAGER BE::System::Application::get()->inputManager
#define ACTIVE_SCENE BE::System::Application::get()->sceneManager.currentScene
#define DRAW BE::System::Application::get()->window->draw

#define TIME BE::System::Application::get()->time

#define DT BE::System::Application::get()->time.dt
#define FPS BE::System::Application::get()->time.fps
#define FDT BE::System::Application::get()->time.fixedDt

/*!
 * @brief Main namespace of the engine
 *
 * Everything related to the engine is within the BE namespace
 *
 */
namespace BE
{
	/*!
	 * @brief Application, Settings etc.
	 *
	 */
	namespace System
	{
		/*!
		 * @brief Main class of the Engine
		 *
		 * Engine main class, you can say it's a "Heart" of the engine,
		 * a singleton containing scene manager, settings and a pointer to the window.
		 * It also provides access to the scene manager for other modules of the engine.
		 *
		 * To work with the engine you need to call run() which starts main loop of the app
		 *
		 * @snippet
		 * #include <BEngine>
		 *
		 * int main()
		 *
		 * {
		 *
		 *	BE::System::Application::get()->run();
		 *
		 * return 0;
		 *
		 * }
		 */
		class Application
		{
			bool running{ false };
			AssetParser assetParser{};
			SettingsParser settingsParser{};

		public:
			Time time;
			/*!
			 * @brief Pointer to the main window
			 *
			 */
			std::unique_ptr<Window> window;

			/*!
			 * @brief The Asset manager used as a storage for Textures, Fonts etc
			 *
			 */
			Assets::AssetManager assetManager{};

			/*!
			 * @brief Input manager handling user input
			 *
			 */
			InputManager inputManager{};

			/*!
			 * @brief Delete copy constructor
			 */
			Application(Application const&) = delete;

			/*!
			* @brief Delete assign operator
			*/
			void operator=(Application const&) = delete;

			/*!
			 * @brief Typical singleton get instance
			 * @return a pointer to the instance of Application
			 */
			static Application * get() {
				static Application instance;
				return &instance;
			}

			/*!
			 * @brief Starts main engine loop
			 *
			 */
			int run();

			/*!
			 * @brief Exit method closes the window and ends the main loop
			 *
			 */
			void exit();

			/*!
			 * @brief Contains map of available scenes
			 *
			 */
			SceneManager sceneManager{};

			Application();
			~Application() { /*Logger::log();*/ }

		};

	} //End namespace System
} //End namespace BE