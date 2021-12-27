#include "Date.h"
#include <chrono>
#include <ctime>   
const int MONTH_QUANTITY = 12;

Date::Date() {
	this->yearNumber = 0;
	this->monthNumber = 0;
}

Date::Date(int monthNumber, int yearNumber) {
	this->yearNumber = yearNumber;
	this->monthNumber = monthNumber;
}
void Date::addMonths(int quantity) {
	// if zero or negative num
	if (quantity < 1) return;

	int newMonths = this->monthNumber + quantity;
	int addMonths = newMonths % MONTH_QUANTITY;
	int addYears = newMonths / MONTH_QUANTITY;

	this->addYears(addYears);
	this->monthNumber = addMonths;
}

// quantity - the positive number to subtract
void Date::subtractMonths(int quantity) {
	// if zero or negative num
	if (quantity < 1) return;

	int newMonth = this->monthNumber - quantity;
	if (newMonth < 0) {
		newMonth = MONTH_QUANTITY - std::abs(newMonth);
	}
	int subtractYears = quantity / MONTH_QUANTITY;

	this->subtractYears(subtractYears);
}

void Date::addYears(int quantity) {
	// if zero or negative num
	if (quantity < 1) return;

	this->yearNumber += quantity;
}
void Date::subtractYears(int quantity) {
	// if zero or negative num
	if (quantity < 1) return;

	this->yearNumber -= quantity;
}

int Date::getCurrentMonthNum() {
	return std::stoi(this->getCurrentData("%m"));;
}

int Date::getCurrentYear() {
	return std::stoi(this->getCurrentData("%Y"));
}

std::string Date::getCurrentData(std::string format) {
	std::time_t timer = std::time(0);
	std::tm bt{};
#if defined(__unix__)
	localtime_r(&timer, &bt);
#elif defined(_MSC_VER)
	localtime_s(&bt, &timer);
#else
	static std::mutex mtx;
	std::lock_guard<std::mutex> lock(mtx);
	bt = *std::localtime(&timer);
#endif
	char buf[64];
	return { buf, std::strftime(buf, sizeof(buf), format.c_str(), &bt) };
}

void Date::setCurrentDate() {
	this->monthNumber = this->getCurrentMonthNum();
	this->yearNumber = this->getCurrentYear();
}

bool Date::isEqual(Date dateForÑomparison) {
	if (dateForÑomparison.yearNumber == this->yearNumber
		&& dateForÑomparison.monthNumber == this->monthNumber) 
		return false;

	return true;
}

std::string Date::toString() {
	return
		std::to_string(monthNumber)
		+ "."
		+ std::to_string(yearNumber);
}

bool Date::operator==(Date dateForÑomparison) {
	if (dateForÑomparison.yearNumber == this->yearNumber
		&& dateForÑomparison.monthNumber == this->monthNumber)
		return false;

	return true;
}

// Using for month, for year use method
void Date::operator+(int quantity) {
	// if zero or negative num
	if (quantity < 1) return;

	int newMonths = this->monthNumber + quantity;
	int addMonths = newMonths % MONTH_QUANTITY;
	int addYears = newMonths / MONTH_QUANTITY;

	this->addYears(addYears);
	this->monthNumber = addMonths;
}

// Using for month, for year use method
void Date::operator-(int quantity) {
	// if zero or negative num
	if (quantity < 1) return;

	int newMonth = this->monthNumber - quantity;
	if (newMonth < 0) {
		newMonth = MONTH_QUANTITY - std::abs(newMonth);
	}
	int subtractYears = quantity / MONTH_QUANTITY;

	this->subtractYears(subtractYears);
	this->monthNumber = newMonth;
}