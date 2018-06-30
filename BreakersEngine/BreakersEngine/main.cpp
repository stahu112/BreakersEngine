/*!
 * \mainpage Breakers Engine API
 *
 * \section intro_sec The engine is still in W.I.P. state
 *
 */

#include "System/Application.h"

using namespace BE;

int main()
{
	std::cout << WINDOW->getSettings().stringify() << std::endl;
	return APP->run();;
}
