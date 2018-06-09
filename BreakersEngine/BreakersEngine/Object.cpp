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
void BE::Object::deActivate() {
	if (!active) return;
	else
	{
		active = false;
		this->onDeactivation();
	}
}
