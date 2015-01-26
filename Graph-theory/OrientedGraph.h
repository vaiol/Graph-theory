#pragma once
#include "Graph.h"

class OrientedGraph : public Graph
{
public:
	OrientedGraph();
	~OrientedGraph();
	int ** createIncedenceMatrix();
	int ** createAdjacencyMatrix();
	bool hasEdge(Edge * edge);
};