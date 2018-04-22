#pragma once

#include "../System/Settings.h"
#include <SFML\Graphics.hpp>
#include <memory>

namespace BE
{
	class Window
	{

		sf::RenderWindow window;
		System::Settings set;

		void init(System::Settings sets = System::Settings{});

	public:

		bool isOpen() { return window.isOpen(); }
		void draw(sf::Drawable& draw) { window.draw(draw); }
		void close() { window.close(); }
		void clear() { window.clear(set.renderSettings.clearColor); }
		void display() { window.display(); }
		void hide() { window.setVisible(false); }
		void show() { window.setVisible(true); }
		void setView(sf::View& view) { window.setView(view); }
		sf::View getView() const { return window.getView(); }

		//Use when settings that need window to be reset had changed
		void reset(System::Settings sets);

		bool pollEvent(sf::Event &e) { return window.pollEvent(e); }


		Window(System::Settings sets = System::Settings{});
		~Window() { window.close(); };
	};

} //End namespace BE