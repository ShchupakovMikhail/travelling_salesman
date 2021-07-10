#include "tree_method.h"



//////////////////////////////////////////////////////////////////////
Node* addNodes(Node* parent, std::vector<Port>& ports)
{
	if (ports.size() == 0)
	{
		return new Node;
	}

	for (size_t i = 0; i < ports.size(); i++)
	{
		std::vector<Port> tmp = ports;
		Node* child = new Node;
		child->port = tmp[i];
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [&child](const auto& port)
			{
				return child->port == port;
			}
		));

		parent->nodes.push_back(child);

		addNodes(child, tmp);
	}

	return parent;
}

//////////////////////////////////////////////////////////////////////
void calculate(const Node* node, const Port& prevPort, const Port& startingPort
	, double curDist, double& minDist)
{
	curDist += distance(prevPort, node->port);

	if (node->nodes.size() == 0) {
		curDist += distance(startingPort, node->port);
		minDist = std::min(minDist, curDist);
		return;
	}

	for (const auto& nextNode : node->nodes) {
		calculate(nextNode, node->port, startingPort, curDist, minDist);
	}
}
