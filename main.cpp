#include "general.h"
#include "permutation_method.h"
#include "tree_method.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
void permutationMethod(const vector<Port>& ports) {
	vector<vector<int>>& routes = producePermutations(ports.size());
	cout << "Length of the shortest path: " << calculateShortestDistance(ports, routes) << endl;
}

//////////////////////////////////////////////////////////////////////
void treeMethod(vector<Port>& ports)
{
	Node* root = new Node;
	root->port = ports[0];
	ports.erase(remove_if(ports.begin(), ports.end(), [&root](const auto& port)
		{
			return root->port == port;
		}
	));
	root = addNodes(root, ports);

	double minDist = numeric_limits<float>::infinity();
	double curDist = 0;
	calculate(root, root->port, root->port, curDist, minDist);

	cout << "Length of the shortest path: " << minDist;
}

//////////////////////////////////////////////////////////////////////
void efficientTreeMethod(vector<Port>& ports)
{
	Node* root = new Node;
	root->port = ports[0];

	double minDist = numeric_limits<float>::infinity();
	double curDist = 0;

	ports.erase(remove_if(ports.begin(), ports.end(), [&root](const auto& port)
		{
			return root->port == port;
		}
	));

	efficientCalcTree(root, ports, root->port, curDist, minDist);

	cout << "Length of the shortest path: " << minDist;
}


//////////////////////////////////////////////////////////////////////
int main()
{
	vector<Port> ports = readPorts();
	if (ports.size() == 0) 
	{
		cout << "Nothing to calculate\n";
		return 0;
	}


	//Uncomment the algorithm you want
	//permutationMethod(ports);
	//treeMethod(ports);
	//efficientTreeMethod(ports);

	return 0;
}
