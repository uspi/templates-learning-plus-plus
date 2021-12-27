#include "Logger.h"
#include <sstream>

Logger::Logger() { }
Logger::Logger(std::string intialStr) {
	this->buffer.push_back(intialStr);
}
void Logger::AddLine(std::string str) {
	this->buffer.push_back(str);
}
std::string Logger::GetFormatedLog() {
	std::string formatedStr;

	for (size_t i = 0; i < this->buffer.size(); i++)
	{
		formatedStr += (this->buffer[i] + "\n");
	}

	return formatedStr;
}