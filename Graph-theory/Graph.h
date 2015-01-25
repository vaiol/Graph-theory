#pragma once 
#include "Edge.h"
#include "Matrix.h"
#include <vector>

class Graph 
{
private:
	bool hasVertex(int id);
	int firstVertex();
protected:
	std::vector<Edge> edges;
	std::vector<Vertex> vertex;
public:
	Graph();
	~Graph();

	Edge * getEdge(int id);
	Vertex * getVertex(int id);
	void addEdge(Edge * edge);
	void addEdge(int vertex1, int vertex2, int weight);
	void addEdge(int vertex1, int vertex2);
	void addVertex();
	void addVertex(int count);
	void removeEdge(Edge * edge);
	void removeVertex(int id);
	void removeVertex(Vertex * vertex);

	friend std::ostream& operator<<(std::ostream&, const Graph&);

	virtual Matrix incedenceMatrix() = 0;
};