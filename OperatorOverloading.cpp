#include <iostream>
#include <chrono>
#include <ctime>   
#include "Printer.h"
#include "Inputs.h"

int main()
{
    Printer p;
    InputPipline ip;
    ip.Start(p);
}