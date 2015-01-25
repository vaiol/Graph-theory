#pragma once
#include "Graph.h"

class OrientedGraph : public Graph
{
public:
	OrientedGraph(Edge * edge);
	~OrientedGraph();
	void removeThisMethodInTheFuture() const;
};