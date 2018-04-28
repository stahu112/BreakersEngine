#include "Logger.h"

#define DEBUG

void BE::Logger::log(const std::string& msg)
{
#ifdef DEBUG
	std::string ret{ "" };

	if (msg != "===LOG END===") ret += "LOG: ";

	ret += msg + "\n";

	std::cout << ret;

	static std::string logFile{};
	logFile += ret;

	if (msg == "===LOG END===")
	{
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
		auto str = oss.str();

		saveLog("Log " + str, logFile);
	}
#endif
}

void BE::Logger::saveLog(const std::string& filename, const std::string& logFileString)
{
	std::fstream file(filename + ".txt", std::ios::out);

	file << logFileString;
	file.close();
}
