#include "Window.h"

namespace BE
{

	Window::Window(System::Settings set)
	{
		unsigned int w = set.getWindowSettings().width, h = set.getWindowSettings().height;

		if (set.getWindowSettings().fullscreen)
			window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w, h), "Breaker", sf::Style::Fullscreen | sf::Style::Default);
		else
			window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w, h), "Breaker", sf::Style::Default);
	}

	Window::~Window()
	{
	}

} //End namespace BE