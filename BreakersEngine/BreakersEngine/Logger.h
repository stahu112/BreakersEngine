#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>

namespace BE
{
	class Logger
	{
		static void saveLog(const std::string& filename, const std::string& logFileString);
	public:
		static void log(const std::string& msg = "===LOG END===");


	};

}