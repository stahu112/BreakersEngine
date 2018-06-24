#pragma once

#include "../System/Settings.h"
#include <SFML\Graphics.hpp>
#include <memory>

namespace BE
{
	/*!
	 * @brief A wrapper class for the SFML RenderWindow ultility
	 *
	 */
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
		System::Settings getSettings() { return set; }
		void setView(sf::View& view) { window.setView(view); }
		sf::View getView() const { return window.getView(); }

		//Use when settings that need window to be reset had changed
		/*!
		 * @brief Closes the window, then reopens it with given Settings
		 * @param sets - Settings of the new window
		 */
		void reset(System::Settings sets);
		bool pollEvent(sf::Event &e) { return window.pollEvent(e); }

		/*!
		 *@brief Construct new window with given settings, if not given then use default settings
		 *
		 */
		Window(System::Settings sets = System::Settings{});
		/*!
		 * @brief Close the window on destruction
		 *
		 */
		~Window() { window.close(); };
	};

} //End namespace BE