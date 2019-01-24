#include "graph.h"

graph::graph(size_t vertices_ext) :
		vertices(vertices_ext)
{
	vector<size_t> row(vertices, 0);
	adjacency_matrix.assign(vertices, row);
}

void graph::insertEdge(size_t vertex_1, size_t vertex_2)
{
	if (vertex_1 > vertices - 1 || vertex_2 > vertices - 1
			|| vertex_1 == vertex_2)
		throw logic_error("insertEdge failed.");
	adjacency_matrix[vertex_1][vertex_2] = 1;
	adjacency_matrix[vertex_2][vertex_1] = 1;
}

size_t graph::differentVertex(size_t vertex_1, size_t vertex_2)
{
	for (size_t v = 0; v < vertices; v++)
		if (v != vertex_1 && v != vertex_2)
			return v;
	throw logic_error("differentVertex failed.");
}

void graph::depthFirstSearch(size_t vertex_start, vector<bool> &visited)
{
	visited[vertex_start] = true;
	for (size_t v = 0; v < vertices; v++)
		if (adjacency_matrix[vertex_start][v] == 1 && visited[v] == false)
			depthFirstSearch(v, visited);
}

bool graph::areAllVisited(vector<bool> visited)
{
	for (size_t v = 0; v < vertices; v++)
		if (visited[v] == false)
			return true;
	return false;
}

bool graph::isWideBridge(size_t vertex_1, size_t vertex_2)
{
	if (adjacency_matrix[vertex_1][vertex_2] == 0)
		return false;
	vector<bool> visited(vertices, false);
	visited[vertex_1] = visited[vertex_2] = true;
	size_t vertex_start = differentVertex(vertex_1, vertex_2);
	depthFirstSearch(vertex_start, visited);
	return areAllVisited(visited);
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
