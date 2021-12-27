#include "Inputs.h"

DateOperations OperationInput::Input(Printer p) {
	do {
		p.Line("Select number of operation:");
		p.Line("1 - Add Months");
		p.Line("2 - Substract Months");
		p.Line("3 - Add Years");
		p.Line("4 - Substract Years");
		std::string numberOfOperationStr;
		std::getline(std::cin, numberOfOperationStr);

		int num;
		try {
			num = std::stoi(numberOfOperationStr);
			num--;
		}
		catch (...) {
			p.Line("Some of your variables cannot be cast to type INT for further calculations.");
			p.Line("---");
			continue;
		}

		if (num < 0 || num > 3) {
			p.Line("Wrong Number of Operation. Please try again.");
			p.Line("---");
			continue;
		}
		return DateOperations(num);

	} while (!this->isCorrectInput);
}

void InputPipline::Start(Printer p) {
	date.setCurrentDate();

	while (true)
	{
		p.Line("===");
		p.Line("Current Date: " + this->date.toString());

		auto operation = oi.Input(p);
		this->dli.Input(p, operation, this->date);
		p.Line("New date: " + this->date.toString());
	}
	
}

void DateManipulationInput::Input(Printer p, DateOperations op, Date &date) {
	switch (op)
	{
	case addMonths:
	{
		p.Line("Please select month quantity to add: ");
		int quantity = this->QuantityInput(p, 1);
		/*date.addMonths(quantity);*/
		date + quantity; 
		break;
	}
	case subtractMonths:
	{
		p.Line("Please select month quantity to subtract: ");
		int quantity = this->QuantityInput(p, 1);
		/*date.subtractMonths(quantity);*/
		date - quantity;
		break;
	}
	case addYears:
	{
		p.Line("Please select years quantity to add: ");
		int quantity = this->QuantityInput(p, 1);
		date.addYears(quantity);
		break;
	}
	case subtractYears:
	{
		p.Line("Please select years quantity to subtract: ");
		int quantity = this->QuantityInput(p, 1);
		date.subtractYears(quantity);
		break;
	}
	default:
		break;
	}
}

int DateManipulationInput::QuantityInput(Printer p, int min) {
	do {
		std::string quantityStr;
		std::getline(std::cin, quantityStr);

		int num;
		try {
			num = std::stoi(quantityStr);
		}
		catch (...) {
			p.Line("Some of your variables cannot be cast to type INT for further calculations.");
			p.Line("---");
			continue;
		}

		if (num < min) p.Line("Please set more then " + std::to_string(min));

		return num;

	} while (!this->isCorrectQuantity);
}

int DateManipulationInput::QuantityInput(Printer p, int min, int max) {
	do {
		p.Line("---");
		std::string quantityStr;
		std::getline(std::cin, quantityStr);

		int num;
		try {
			num = std::stoi(quantityStr);
		}
		catch (...) {
			p.Line("Some of your variables cannot be cast to type INT for further calculations.");
			continue;
		}

		if (num < min) p.Line("Please set more then " + std::to_string(min));
		if (num > max) p.Line("Please set less then " + std::to_string(max));

		return num;
	} while (!this->isCorrectQuantity);
}