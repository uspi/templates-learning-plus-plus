#include "Point.h"

Point::Point() { x = 0; }
Point::Point(Logger& logger) { 
	x = 0; 
	this->logger = logger;
}

void Point::operator =(Point p) {
	this->x = p.x;
}

std::ostream& operator <<(std::ostream& s, Point& p) {
	s << "X: " << p.x << "\n";

	p.logger.AddLine("X: " + p.x);

	return s;
}

std::istream& operator >>(std::istream& s, Point& p) {
	std::cout << "Enter X: " << "\n";
	std::cin >> p.x;

	p.logger.AddLine("Enter X: \n");
	//p.logger.AddLine(std::to_string(p.x));
	
	return s;
}

std::string Point::GetInDialog() {
	return
		"Enter X \n" + std::to_string(this->x);
}
std::string Point::GetOutDialog() {
	return
		"X: " + std::to_string(this->x);
}

std::string Point::to_string(Point& p) {
	return std::to_string(p.x);
}