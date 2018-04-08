#include <iostream>
#include <thread>
#include "Application.h"

using namespace BE;

int main()
{
	System::Application app{};

	std::cout << app.getSettings().stringify() << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	app.run();

	return EXIT_SUCCESS;
}
