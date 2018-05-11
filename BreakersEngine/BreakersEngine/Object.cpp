#include "Object.h"
#include "System\Application.h"

/*!
* @brief Activate object
*
*/
void BE::Object::activate() {
	if (active) return;
	else
	{
		active = true;
		this->onActivation();
	}
}

/*!
* @brief Dectivate object
*
*/
void BE::Object::dectivate() {
	if (!active) return;
	else
	{
		active = false;
		this->onDeactivation();
	}
}

/*!
* @brief called each frame
*
*/

void BE::Object::draw()
{
	Logger::log(tag + " Draw");
	sf::Sprite sp;
	sp.setTexture(System::Application::get()->assetManager.getTexture(Assets::Texture::dummyTexture));
	System::Application::get()->window->draw(sp);
}
