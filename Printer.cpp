#include "Printer.h"

void Printer::Line(std::string text) {
	std::cout << text + "\n";
}
void Printer::Line(int number) {
	this->Line(std::to_string(number));
}
void Printer::Line(std::string text, int number) {
	this->Line(text + std::to_string(number));
}
void Printer::Line(std::string text, double number) {
	this->Line(text + std::to_string(number));
}