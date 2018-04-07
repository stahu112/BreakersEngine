#include <iostream>
#include "Settings.h"
#include "Window.h"
#include <thread>

using namespace BE;

int main()
{

	System::Settings set{ {1000, 800, false} };
	
	std::cout << set.stringify() << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	Window window{ set };


	while (window.isOpen())
	{

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) window.close();
		}

		window.clear(sf::Color::Green);
		window.display();
	}
	

	return EXIT_SUCCESS;
}
