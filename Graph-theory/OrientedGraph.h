#pragma once
#include "Graph.h"


#include "NonOrientedGraph.h"

class OrientedGraph : public Graph
{
public:
	OrientedGraph();
	OrientedGraph(Graph * graph);
	~OrientedGraph();
	std::vector<std::vector<int>> createIncedenceMatrix();
	std::vector<std::vector<int>> createAdjacencyMatrix();
	bool hasEdge(Edge * edge);
};