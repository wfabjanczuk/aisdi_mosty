#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int main()
{
	size_t vertices, vertex_1, vertex_2;
	cin >> vertices;
	graph g(vertices);
	do
	{
		cin >> vertex_1;
		if (cin.eof() == true)
			break;
		cin >> vertex_2;
		g.insertEdge(vertex_1, vertex_2);
	} while (true);

	vector<pair<size_t, size_t>> wide_bridges = g.findWideBridges();
	for (auto it = wide_bridges.begin(); it != wide_bridges.end(); ++it)
		cout << it->first << " " << it->second << endl;
	return 0;
}
