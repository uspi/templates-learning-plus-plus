#pragma once
#ifndef POINT_H
#define POINT_H
#endif
#include <iostream>
#include "Logger.h"

class Point {
public:
	Logger logger;
	int x;
	Point();
	Point(Logger& logger);
	void operator =(Point p);
	friend std::ostream& operator <<(std::ostream& s, Point& p);
	friend std::istream& operator >>(std::istream& s, Point& p);
	std::string GetInDialog();
	std::string GetOutDialog();
	std::string to_string(Point& p);
};