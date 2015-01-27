#pragma once
#include "Edge.h"
#include <vector>

class Graph 
{
private:
	//---graphs
	bool hasVertex(int id);
	int firstVertex();
	virtual bool hasEdge(Edge * edge) = 0;
	//---matrices
	int ** incedenceMatrix;
	int ** adjacencyMatrix;
	int ** distanceMatrix;
	int ** reachabilityMatrix;
	virtual int ** createIncedenceMatrix() = 0;
	virtual int ** createAdjacencyMatrix() = 0;
	int ** createDistanceMatrix();
	int ** createReachabilityMatrix();
	int ** degreeMatrix(int ** matrix, int degree);
	void outputSquareMatrix(int ** matrix, int line);
protected:
	std::vector<Edge> edges;
	std::vector<Vertex> vertices;
public:
	//---graphs
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
	void outputDistanceMatrix();
	void outputReachabilityMatrix();
	int ** getAdjacencyMatrix();
	int ** getIncedenceMatrix();
	int ** getDistanceMatrix();
	void update();
	//---operators
	friend std::ostream& operator<<(std::ostream&, const Graph&);
};