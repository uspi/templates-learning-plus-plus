#pragma once
#ifndef DOT_H
#define DOT_H
#endif
#include <iostream>
#include <string>
#include <vector>
#include "Logger.h"
#include "Point.h"

template<class T>
class Dot {
public:
	Logger& logger;
	T position;
	Dot(Logger &l);
	void operator = (Dot d);
	template <typename T>
	friend std::ostream& operator<<(std::ostream& s, Dot<T>& t);
	template <typename T>
	friend std::istream& operator>>(std::istream& s, Dot<T>& t);
	
	~Dot();
};



