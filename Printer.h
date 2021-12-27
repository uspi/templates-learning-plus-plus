#pragma once
#ifndef PRINTER_H
#define PRINTER_H
#endif
#include <iostream>
#include <string>

class Printer {
public:
	void Line(std::string text);
	void Line(int number);
	void Line(std::string text, int number);
	void Line(std::string text, double number);
};