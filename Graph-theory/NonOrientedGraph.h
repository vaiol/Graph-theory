#pragma once

#include "Graph.h"

class NonOrientedGraph : public Graph
{
public:
	NonOrientedGraph();
	~NonOrientedGraph();
	int ** createIncedenceMatrix();
	int ** createAdjacencyMatrix();
	bool hasEdge(Edge * edge);
};