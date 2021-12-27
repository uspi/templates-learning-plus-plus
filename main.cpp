#include <iostream>
#include <vector>
#include <string>
#include "Point.h"
#include "Dot.h"
#include "Dot.cpp"
#include "File.h"

int main()
{
    Logger log;
    File file("out.txt");

    Dot<int> i = Dot<int>(log);
    Dot<float> f = Dot<float>(log);
    Dot<double> d = Dot<double>(log);
    Dot<Point> p = Dot<Point>(log);

    // int
    std::cout << "You enter INT" << "\n";
    log.AddLine("You enter INT");
    std::cin >> i;
    
    // float
    std::cout << "You enter FLOAT" << "\n";
    log.AddLine("You enter FLOAT");
    std::cin >> f;

    // double
    std::cout << "You enter DOUBLE" << "\n";
    log.AddLine("You enter DOUBLE");
    std::cin >> d;

    // point - custom type
    std::cout << "You enter POINT" << "\n";
    log.AddLine("You enter POINT");
    std::cin >> p;

    std::cout << "All your input, one by one: " << "\n";
    log.AddLine("All your input, one by one: ");
    std::cout << i << f << d << p;

    // save to file
    file.createText(log.GetFormatedLog());
}