#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>

namespace BE
{
	/*!
	 * @brief Logging into the console and file
	 *
	 * Contains static methods for console logging
	 */
	class Logger
	{
		static void saveLog(const std::string& filename, const std::string& logFileString);
	public:

		/*!
		 * @brief Log message to the console
		 *
		 * Logs given message to the console and saves the log.txt file if DEBUG is defined
		 * @param msg - Message to log
		 */
		static void log(const std::string& msg = "===LOG END===", bool sayLog = true);


	};

}