#pragma once
#include <map>
#include <SFML\Graphics.hpp>

#define KEY sf::Keyboard::Key
#define MBUTTON sf::Mouse::Button
#define BINDING(x,y) std::make_pair(x,y)

namespace BE
{

	class InputManager
	{
		enum InputState
		{
			PRESSED,
			HELD,
			RELEASED,
			IDLE
		};

		class KeyInput
		{
			InputState oldState = IDLE;
			KEY input;
		public:
			InputState state = IDLE;
			KeyInput(KEY key) : input(key) {}
			void updateState();
		};
		class MouseInput
		{
			InputState oldState = IDLE;
			MBUTTON input;
		public:
			InputState state = IDLE;
			MouseInput(MBUTTON butt) : input(butt) {}
			void updateState();
		};

		//Parse the mappings from file
		std::map<std::string, KeyInput> keyboard;
		std::map<std::string, MouseInput> mouse;

	public:
		void updateKeyboard();
		void updateMouse();
		void deleteKeyboardBinding(std::string str);
		void deleteMouseBinding(std::string str);
		void addKeyboardBinding(std::pair<std::string, KEY> pair);
		void addMouseBinding(std::pair<std::string, MBUTTON> pair);

		//KEYBOARD
		bool keyPressed(std::string str);
		bool keyHeld(std::string str);
		bool keyReleased(std::string str);

		//MOUSE
		bool mButtonPressed(std::string str);
		bool mButtonHeld(std::string str);
		bool mButtonReleased(std::string str);
	};

}