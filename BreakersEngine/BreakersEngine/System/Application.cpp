#include "Application.h"


namespace BE
{
	namespace System
	{
		void Application::run()
		{
			running = true;
			window = std::make_unique<Window>(settings);

			sf::Clock dtClock;
			sf::Time dt;

			while (running)
			{

				dt = dtClock.restart();
				Time::dt = dt.asSeconds();
				Time::fps = 1 / dt.asSeconds();

				sf::Event e;
				while (window->pollEvent(e))
				{
					if (e.type == sf::Event::Closed) exit();
				}

				sceneManager.currentScene->stateMachine.updateLoop();

				window->clear();
				window->display();
			}

		}

		void Application::exit()
		{
			//TODO Save or stuff
			running = false;
			window->close();
		}

		Application::Application()
		{
			//TODO parse settings from file
		}

	} //End namespace System
} //End namespace BE