#pragma once

#include <algorithm>

#include "general.h"



//////////////////////////////////////////////////////////////////////
Node* addNodes(Node* parent, std::vector<Port>& ports);

//////////////////////////////////////////////////////////////////////
void calculate(const Node* node, const Port& prevPort, const Port& startingPort
	, double curDist, double& minDist);
