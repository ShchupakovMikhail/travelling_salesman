#include "permutation_method.h"



//////////////////////////////////////////////////////////////////////
std::vector<int>& initialize(const int& count)
{
	std::vector<int>* portsNumbers = new std::vector<int>;
	for (int i = 0; i < count; i++)
	{
		portsNumbers->push_back(i + 1);
	}

	return *portsNumbers;
}

//////////////////////////////////////////////////////////////////////
std::vector<std::vector<int>>& producePermutations(const int& count)
{
	int numberOfCities = count - 1;
	std::vector<std::vector<int>>* permulations = new std::vector<std::vector<int>>;
	if (numberOfCities <= 0)
	{
		return *permulations;
	}

	std::vector<int> initial = initialize(numberOfCities);
	if (numberOfCities == 1) {
		permulations->push_back(initial);
		return *permulations;
	}

	auto head = --initial.end();
	auto tail = initial.end();
	bool allPermulations = false;

	while (!allPermulations)
	{
		permulations->push_back(initial);
		while (*(--head) >= *(--tail))
		{
			if (head == initial.begin())
			{
				allPermulations = true;
				break;
			}
		}

		tail = initial.end();
		while (--tail != head)
		{
			if (*tail > * head) {
				std::swap(*head, *tail);
				break;
			}
		};

		reverse(next(head), initial.end());

		head = --initial.end();
		tail = initial.end();
	}

	return *permulations;
}

//////////////////////////////////////////////////////////////////////
double calculateShortestDistance(const std::vector<Port>& ports, const std::vector<std::vector<int>> routes)
{
	double shortest = INF;
	double route = 0;
	Port current = ports[0];

	for (const auto& r : routes)
	{
		current = ports[0];
		for (const auto& p : r)
		{
			route += distance(current, ports[p]);
			current = ports[p];
		}
		route += distance(current, ports[0]);
		current = ports[0];

		shortest = std::min(shortest, route);
		route = 0;
	}

	shortest = shortest != INF ? shortest : 0;
	return shortest;
}