#include "Application.h"

namespace BE
{
	namespace System
	{
		void Application::run()
		{
			window = std::make_unique<Window>(settings);

			while (window->isOpen())
			{
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


		Application::~Application()
		{
		}

	} //End namespace System
} //End namespace BE