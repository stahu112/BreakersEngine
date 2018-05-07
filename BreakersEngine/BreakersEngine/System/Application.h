#pragma once

#include <iostream>
#include "Settings.h"
#include "../Logger.h"
#include "../GUI/Window.h"
#include "Time.h"
#include <thread>
#include "../SceneManager.h"

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
			Settings settings{};

			bool running{ false };

		public:
			/*!
			 * @brief Pointer to the main window
			 *
			 */
			std::unique_ptr<Window> window;


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
			void run();

			/*!
			 * @brief Exit method closes the window and ends the main loop
			 *
			 */
			void exit();

			/*!
			 * @brief Contains map of available scenes
			 *
			 */
			SceneManager sceneManager;

			/*!
			 * @brief returns settings of the window
			 *
			 */
			Settings getSettings() { return settings; }

			Application();
			~Application() { /*Logger::log();*/ }

		};

	} //End namespace System
} //End namespace BE