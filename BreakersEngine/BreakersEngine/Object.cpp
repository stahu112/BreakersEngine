#include "Object.h"

/*!
* @brief Dectivate object
*
*/


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

void BE::Object::dectivate() {
	if (!active) return;
	else
	{
		active = false;
		this->onDeactivation();
	}
}
