#include <iostream>
#include <thread>
#include <cstdlib>
#include "Application.h"

using namespace BE;

int main()
{
	System::Application app{};

	std::cout << app.getSettings().stringify() << std::endl;
	int timer = 1;
	int time = 5;
		std::cout << std::endl;
		std::cout << "Settings should change after " << time << " seconds";

	while (timer < time)
	{
		std::string str{};
		str += ".";
		std::cout << str;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		timer++;
	}
	//app.run();
	system("cls");
	app.test();

	return EXIT_SUCCESS;
}
