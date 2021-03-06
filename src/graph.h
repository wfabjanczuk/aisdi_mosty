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

	inline bool edge(size_t vertex_1, size_t vertex_2) const;
	inline void setEdge(size_t vertex_1, size_t vertex_2, bool status);

	size_t differentVertex(vector<size_t> vertices_ext) const;
	void depthFirstWalk(size_t vertex_start, size_t &visited_count,
			vector<bool> &visited) const;
	bool isWideBridge(size_t vertex_1, size_t vertex_2) const;
public:
	explicit graph(size_t vertices_count = 0);
	void insertEdge(size_t vertex_1, size_t vertex_2);
	vector<pair<size_t, size_t>> findWideBridges() const;
};

#endif /* GRAPH_H_ */
