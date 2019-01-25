#include "graph.h"

graph::graph(size_t vertices_ext) :
		vertices(vertices_ext)
{
	adjacency_matrix.assign(vertices * vertices, false);
}

inline bool graph::edge(size_t vertex_1, size_t vertex_2)
{
	return adjacency_matrix[vertex_1 * vertices + vertex_2];
}

inline void graph::setEdge(size_t vertex_1, size_t vertex_2, bool status)
{
	adjacency_matrix[vertex_1 * vertices + vertex_2] = adjacency_matrix[vertex_2
			* vertices + vertex_1] = status;
}

void graph::insertEdge(size_t vertex_1, size_t vertex_2)
{
	if (vertex_1 > vertices - 1 || vertex_2 > vertices - 1
			|| vertex_1 == vertex_2)
		throw logic_error("insertEdge failed.");
	setEdge(vertex_1, vertex_2, true);
}

size_t graph::differentVertex(size_t vertex_1, size_t vertex_2)
{
	for (size_t v = 0; v < vertices; v++)
		if (v != vertex_1 && v != vertex_2)
			return v;
	throw logic_error("differentVertex failed.");
}

void graph::depthFirstWalk(size_t vertex_start, size_t &visited_count,
		vector<bool> &visited)
{
	visited_count++;
	visited[vertex_start] = true;
	for (size_t v = 0; v < vertices; v++)
		if (edge(vertex_start, v) == true && visited[v] == false)
			depthFirstWalk(v, visited_count, visited);
}

bool graph::isWideBridge(size_t vertex_1, size_t vertex_2)
{
	if (edge(vertex_1, vertex_2) == false)
		return false;
	vector<bool> visited(vertices, false);
	visited[vertex_1] = visited[vertex_2] = true;
	size_t vertex_start = differentVertex(vertex_1, vertex_2);
	size_t visited_count = 2;
	depthFirstWalk(vertex_start, visited_count, visited);
	return (visited_count != vertices);
}

vector<pair<size_t, size_t>> graph::findWideBridges()
{
	vector<pair<size_t, size_t>> wide_bridges;
	for (size_t v = 0; v < vertices; v++)
		for (size_t w = v + 1; w < vertices; w++)
			if (isWideBridge(v, w))
				wide_bridges.push_back(make_pair(v, w));
	return wide_bridges;
}
