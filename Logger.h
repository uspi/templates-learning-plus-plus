#pragma once
#ifndef LOGGER_H
#define LOGGER_H
#endif
#include <iostream>
#include <string>
#include <vector>

class Logger {
public:
	std::vector<std::string> buffer;
	Logger();
	Logger(std::string initialStr);
	void AddLine(std::string str);
	std::string GetFormatedLog();
};