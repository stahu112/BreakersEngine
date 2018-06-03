/*!
 * \mainpage Breakers Engine API
 *
 * \section intro_sec The engine is still in W.I.P. state, I believe it should be in a usable state before the end of june
 *
 */

#include "System/Application.h"

using namespace BE;

int main()
{
	std::cout << APP->getSettings().stringify() << std::endl;
	APP->run();
	return EXIT_SUCCESS;
}
