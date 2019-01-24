#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <stdexcept>
#include <utility>

using namespace std;

class graph
{
	size_t vertices;
	vector<bool> adjacency_matrix;

	size_t differentVertex(size_t vertex_1, size_t vertex_2);
	void depthFirstWalk(size_t vertex_start, vector<bool> &visited);
	bool areAllVisited(vector<bool> visited);
	bool isWideBridge(size_t vertex_1, size_t vertex_2);
public:
	explicit graph(size_t vertices_ext = 0);
	void insertEdge(size_t vertex_1, size_t vertex_2);
	vector<pair<size_t, size_t>> findWideBridges();
};

#endif /* GRAPH_H_ */
