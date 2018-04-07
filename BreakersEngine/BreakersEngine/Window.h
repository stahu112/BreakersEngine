#pragma once

#include "Settings.h"
#include <SFML\Graphics.hpp>
#include <memory>

namespace BE
{
	class Window
	{

		std::unique_ptr<sf::RenderWindow> window;

	public:

		bool isOpen() { return window->isOpen(); }
		void draw(sf::Drawable& draw) { window->draw(draw); }
		void close() { window->close(); }
		void clear(const sf::Color col = sf::Color::White) { window->clear(col); }
		void display() { window->display(); }

		bool pollEvent(sf::Event &e) { return window->pollEvent(e); }

		Window(System::Settings set = System::Settings{});
		~Window();
	};

} //End namespace BE