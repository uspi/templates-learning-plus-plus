#pragma once
#ifndef DATE_H
#define DATE_H
#endif
#include <string>

// Stores the day of the month and month. 
// Allows you to compare, subtract, add days.
class Date {
private:
	std::string getCurrentData(std::string format);
public:
	int monthNumber;
	int yearNumber;	
	Date();
	Date(int monthNumber, int yearNumber);
	void addMonths(int quantity);
	void subtractMonths(int quantity);
	void addYears(int quantity);
	void subtractYears(int quantity);
	int getCurrentMonthNum();
	int getCurrentYear();
	void setCurrentDate();
	bool isEqual(Date dateFor—omparison);
	std::string toString();
	bool operator ==(Date dateForComparison);
	// Using for month, for year use method
	void operator +(int quantity);
	// Using for month, for year use method
	void operator -(int quantity);
};