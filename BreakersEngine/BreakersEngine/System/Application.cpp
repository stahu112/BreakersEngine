#include "Application.h"
#include <string>

namespace BE
{
	namespace System
	{
		void Application::run()
		{
			running = true;

			sf::Clock dtClock, fixedClock;
			sf::Time dt;

			std::thread fixedUpdateThread([&]() {
				while (running) {
					sceneManager.currentScene->stateMachine->fixedUpdateLoop();
					std::this_thread::sleep_for(std::chrono::milliseconds(time.fixedDt));
				}
			});

			while (running)
			{

				dt = dtClock.restart();
				time.dt = dt.asSeconds() * time.timeScale;
				time.fps = 1 / dt.asSeconds();

				inputManager.updateKeyboard();
				inputManager.updateMouse();

				sf::Event e;
				while (window->pollEvent(e)) {
					if (e.type == sf::Event::Closed) exit();
				}

				window->clear();
				sceneManager.currentScene->stateMachine->updateLoop();
				
				window->display();
			}
			fixedUpdateThread.join();
		}

		void Application::exit()
		{
			//TODO Save or stuff
			running = false;
			window->close();
		}

		Application::Application()
		{
			assetManager = assetParser.parse();
			settings = settingsParser.parse();

			inputManager.addKeyboardBinding(BINDING("test", KEY::W));
			inputManager.addKeyboardBinding(BINDING("Active", KEY::A));
			inputManager.addMouseBinding(BINDING("M1", MBUTTON::Left));

			window = std::make_unique<Window>(settings);
		}

	} //End namespace System
} //End namespace BE