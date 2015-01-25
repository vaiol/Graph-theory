#include "Graph.h"

class NonOrientedGraph : public Graph
{
public:
	NonOrientedGraph(Edge * edge);
	~NonOrientedGraph();
	void removeThisMethodInTheFuture() const;
};