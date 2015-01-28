#pragma once
#include "Graph.h"

class OrientedGraph : public Graph
{
public:
	OrientedGraph();
	~OrientedGraph();
	std::vector<std::vector<int>> createIncedenceMatrix();
	std::vector<std::vector<int>> createAdjacencyMatrix();
	bool hasEdge(Edge * edge);
};