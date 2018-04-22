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
	public:
		static void log(const std::string& msg = "===LOG END===");
		static void saveLog(const std::string& filename, const std::string& logFileString);

	};

}