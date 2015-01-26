#pragma once
#include "Edge.h"
#include <vector>

class Graph 
{
private:
	int** incedenceMatrix;
	int** adjacencyMatrix;
	bool hasVertex(int id);
	int firstVertex();
	virtual bool hasEdge(Edge * edge) = 0;
	virtual int ** createIncedenceMatrix() = 0;
	virtual int ** createAdjacencyMatrix() = 0;
protected:
	std::vector<Edge> edges;
	std::vector<Vertex> vertices;
public:
	Graph();
	~Graph();

	Edge * getEdge(int id);
	Vertex * getVertex(int id);
	bool addEdge(Edge * edge);
	bool addEdge(int vertex1, int vertex2, int weight);
	bool addEdge(int vertex1, int vertex2);
	void addVertex();
	void addVertex(int count);
	void removeEdge(Edge * edge);
	void removeVertex(int id);
	void removeVertex(Vertex * vertex);
	//---matrices
	void outputIncedenceMatrix();
	void outputAdjacencyMatrix();
	int ** getAdjacencyMatrix();
	int ** getIncedenceMatrix();
	void update();
	//---operators
	friend std::ostream& operator<<(std::ostream&, const Graph&);
};