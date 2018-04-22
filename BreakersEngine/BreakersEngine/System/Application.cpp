#include "Application.h"

namespace BE
{
	namespace System
	{
		void Application::run()
		{
			window = std::make_unique<Window>(settings);

			sf::Clock dtClock;
			sf::Time dt;

			while (window->isOpen())
			{

				dt = dtClock.restart();
				Time::dt = dt.asSeconds();
				Time::fps = 1 / dt.asSeconds();

				sf::Event e;
				while (window->pollEvent(e))
				{
					if (e.type == sf::Event::Closed) window->close();
				}

				window->clear();
				window->display();
			}
		}

		Application::Application()
		{
			//TODO parse settings from file
		}

	} //End namespace System
} //End namespace BE