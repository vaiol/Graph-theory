#pragma once 
#include "Edge.h"
#include <vector>

class AbstractGraph 
{
private:
	std::vector<Edge> edges;
public:
	AbstractGraph(Edge * edges);
	~AbstractGraph();
	Edge * getEdge(int id);
	void removeEdge(int id);
	void removeEdge(Edge * edge);
	void removeVertex(int id);
	void removeVertex(Vertex * vertex);
	void addEdge(Edge * edge);
	friend std::ostream& operator<<(std::ostream&, const AbstractGraph&);
};