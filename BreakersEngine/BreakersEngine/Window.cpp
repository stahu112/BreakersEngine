#include "Window.h"

namespace BE
{

	Window::Window(System::Settings set)
	{
		unsigned int w = set.getWindowSettings().width, h = set.getWindowSettings().height;

		if (set.getWindowSettings().fullscreen)
			window.create(sf::VideoMode(w, h), "Breaker", sf::Style::Fullscreen | sf::Style::Default);
		else
			window.create(sf::VideoMode(w, h), "Breaker", sf::Style::Default);
	}

} //End namespace BE