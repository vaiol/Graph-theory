#include "Graph.h"

class NonOrientedGraph : public Graph
{
public:
	NonOrientedGraph();
	~NonOrientedGraph();
	Matrix incedenceMatrix();
};