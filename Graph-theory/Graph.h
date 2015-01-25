#pragma once 
#include "Edge.h"
#include <vector>

class Graph 
{
private:
	std::vector<Edge> edges;
public:
	Graph(Edge * edge);
	~Graph();
	Edge * getEdge(int id);
	void removeEdge(int id);
	void removeEdge(Edge * edge);
	void removeVertex(int id);
	void removeVertex(Vertex * vertex);
	void addEdge(Edge * edge);
	friend std::ostream& operator<<(std::ostream&, const Graph&);
	virtual void removeThisMethodInTheFuture() const = 0;
};