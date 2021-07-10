#include "general.h"



//////////////////////////////////////////////////////////////////////
bool operator==(const Port& lhs, const Port& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

//////////////////////////////////////////////////////////////////////
double distance(const Port& first, const Port& second)
{
	double xLength = abs(first.x - second.x);
	double yLength = abs(first.y - second.y);
	return sqrt(pow(xLength, 2) + pow(yLength, 2));
}

//////////////////////////////////////////////////////////////////////
std::vector<Port>& readPorts() {
	int count;
	const std::string greeting = "Enter a number of port(including the start port): ";
	std::cout << greeting;
	std::cin >> count;
	while (count < 0)
	{
		std::cout << "Enter a non-negative number!\n" + greeting;
		std::cin >> count;
	}

	std::vector<Port>* ports = new std::vector<Port>;
	for (int i = 0; i < count; i++)
	{
		double x = 0.0;
		double y = 0.0;

		std::cout << "Enter coordinates for port " + std::to_string(i) << "\nx: ";
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;

		ports->push_back({ x, y });
	}

	return *ports;
}