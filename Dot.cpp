#include "Dot.h"
#include "Point.h"
#include <string>

template class Dot<int>;
template class Dot<float>;
template class Dot<double>;
template class Dot<Point>;

template <typename T>
Dot<T>::Dot(Logger& _logger) : logger(_logger) { }

template <typename T>
void Dot<T>::operator =(Dot<T> d) {
	this->position = d.position;
}

template<typename T>
std::ostream& operator<<(std::ostream& s, Dot<T>& t)
{
	s << "Posititon: " << t.position << "\n";

	t.logger.AddLine("Position: ");
	//t.logger.AddLine(std::to_string(t.position));

	return s;
}

template <typename T>
std::istream& operator>>(std::istream& s, Dot<T>& t) {
	std::cout << "Enter a position: " << "\n";
	std::cin >> t.position;

	t.logger.AddLine("Enter a position: ");
	//t.logger.AddLine(std::to_string(t.position));

	return s;
}

template <typename T>
Dot<T>::~Dot() { }