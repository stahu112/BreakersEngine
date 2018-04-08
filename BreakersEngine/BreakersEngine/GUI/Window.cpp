#include "Window.h"

namespace BE
{

	void Window::init(System::Settings sets)
	{
		set = sets;
	}

	void Window::reset(System::Settings sets)
	{
		this->init(sets);

		//CREATE WINDOW
		unsigned int w = set.windowSettings.width, h = set.windowSettings.height;

		if (set.windowSettings.fullscreen)
			window.create(sf::VideoMode(w, h), "Breaker", sf::Style::Fullscreen | sf::Style::Default);
		else
			window.create(sf::VideoMode(w, h), "Breaker", sf::Style::Default);
	}

	Window::Window(System::Settings sets)
	{
		this->init(sets);

		//CREATE WINDOW
		unsigned int w = set.windowSettings.width, h = set.windowSettings.height;

		if (set.windowSettings.fullscreen)
			window.create(sf::VideoMode(w, h), "Breaker", sf::Style::Fullscreen | sf::Style::Default);
		else
			window.create(sf::VideoMode(w, h), "Breaker", sf::Style::Default);

		//APPLY RENDER SETTINGS
		window.setFramerateLimit(set.renderSettings.fpsLimit);
		window.setVerticalSyncEnabled(set.renderSettings.verticalSync);
	}

} //End namespace BE