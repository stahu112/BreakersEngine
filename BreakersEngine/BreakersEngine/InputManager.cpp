#include "InputManager.h"
#include "Exceptions.h"

void BE::InputManager::updateKeyboard()
{
	for (auto &x : keyboard)
		x.second.updateState();
}

void BE::InputManager::updateMouse()
{
	for (auto &x : mouse)
		x.second.updateState();
}

void BE::InputManager::deleteKeyboardBinding(std::string str)
{
	if (keyboard.find(str) == keyboard.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		keyboard.erase(str);
}

void BE::InputManager::deleteMouseBinding(std::string str)
{
	if (mouse.find(str) == mouse.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		mouse.erase(str);
}

void BE::InputManager::addKeyboardBinding(std::pair<std::string, KEY> pair)
{
	if (keyboard.find(pair.first) != keyboard.end())
		throw Exceptions::EXBindingAlreadyExists{};
	else
	{
		KeyInput k{ pair.second };
		auto pair1 = std::make_pair(pair.first, k);
		keyboard.insert(pair1);
	}
}

void BE::InputManager::addMouseBinding(std::pair<std::string, MBUTTON> pair)
{
	if (mouse.find(pair.first) != mouse.end())
		throw Exceptions::EXBindingAlreadyExists{};
	else
	{
		MouseInput b{ pair.second };
		auto pair1 = std::make_pair(pair.first, b);
		mouse.insert(pair);
	}
}


bool BE::InputManager::keyPressed(std::string str)
{
	if (keyboard.find(str) == keyboard.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		return (keyboard.at(str).state == PRESSED);
}

bool BE::InputManager::keyHeld(std::string str)
{
	if (keyboard.find(str) == keyboard.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		return (keyboard.at(str).state == HELD || keyboard.at(str).state == PRESSED);
}

bool BE::InputManager::keyReleased(std::string str)
{
	if (keyboard.find(str) == keyboard.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		return (keyboard.at(str).state == RELEASED);
}

bool BE::InputManager::mButtonPressed(std::string str)
{
	if (mouse.find(str) == mouse.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		return (mouse.at(str).state == PRESSED);
}

bool BE::InputManager::mButtonHeld(std::string str)
{
	if (mouse.find(str) == mouse.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		return (mouse.at(str).state == HELD || mouse.at(str).state == PRESSED);
}

bool BE::InputManager::mButtonReleased(std::string str)
{
	if (mouse.find(str) == mouse.end())
		throw Exceptions::EXBindingDoesntExists{};
	else
		return (mouse.at(str).state == RELEASED);
}

void BE::InputManager::KeyInput::updateState()
{
	if (sf::Keyboard::isKeyPressed(input)) {
		if (oldState == IDLE) {
			state = PRESSED;
			oldState = PRESSED;
		}
		else if (oldState == PRESSED)
		{
			state = HELD;
			oldState = HELD;
		}
		else if (oldState == HELD)
		{
			state = HELD;
			oldState = HELD;
		}
		else if (oldState == RELEASED)
		{
			state = IDLE;
			oldState = IDLE;
		}

	}
	else {
		if (oldState == IDLE) {
			state = IDLE;
			oldState = IDLE;
		}
		else if (oldState == PRESSED)
		{
			state = RELEASED;
			oldState = RELEASED;
		}
		else if (oldState == HELD)
		{
			state = RELEASED;
			oldState = RELEASED;
		}
		else if (oldState == RELEASED)
		{
			state = IDLE;
			oldState = IDLE;
		}


	}
}

void BE::InputManager::MouseInput::updateState()
{
	if (sf::Mouse::isButtonPressed(input)) {

		if (oldState == IDLE) {
			state = PRESSED;
			oldState = PRESSED;
		}
		else if (oldState == PRESSED)
		{
			state = HELD;
			oldState = HELD;
		}
		else if (oldState == HELD)
		{
			state = HELD;
			oldState = HELD;
		}
		else if (oldState == RELEASED)
		{
			state = IDLE;
			oldState = IDLE;
		}
	}
	else {
		if (oldState == IDLE) {
			state = IDLE;
			oldState = IDLE;
		}
		else if (oldState == PRESSED)
		{
			state = RELEASED;
			oldState = RELEASED;
		}
		else if (oldState == HELD)
		{
			state = RELEASED;
			oldState = RELEASED;
		}
		else if (oldState == RELEASED)
		{
			state = IDLE;
			oldState = IDLE;
		}

	}
}
