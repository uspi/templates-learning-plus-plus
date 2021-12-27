#pragma once
#ifndef INPUTS_H
#define INPUTS_H
#endif
#include "DateOperationsEnum.cpp"
#include "Printer.h"
#include "Date.h"

class OperationInput {
public:
	bool isCorrectInput = false;
	DateOperations Input(Printer p);
};

class DateManipulationInput {
private:
	int QuantityInput(Printer p, int min, int max);
	int QuantityInput(Printer p, int min);
public:
	bool isCorrectInput = false;
	bool isCorrectQuantity = false;
	void Input(Printer p, DateOperations op, Date &date);
};

class InputPipline {
public: 
	OperationInput oi;
	DateManipulationInput dli;
	Date date;

	void Start(Printer p);
};
