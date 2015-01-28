#pragma once

#include "Graph.h"

class NonOrientedGraph : public Graph
{
public:
	NonOrientedGraph();
	~NonOrientedGraph();
	std::vector<std::vector<int>> createIncedenceMatrix();
	std::vector<std::vector<int>> createAdjacencyMatrix();
	bool hasEdge(Edge * edge);
};