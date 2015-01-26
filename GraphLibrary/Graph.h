#pragma once
#include "Edge.h"
#include <vector>
class Graph
{
private:
	std::vector<Edge> edges;
	std::vector<Vertex> vertexes;
	int id;
public:
	Graph();
	~Graph();
	void setId(int id);	
	void addVertex(Vertex *vertex);
	void addVertex(int id);
	void removeVertex(Vertex *vertex);
	void removeVertex(int id);
	void outputVertexes();
	bool checkVertex(Vertex *vertex);
	bool checkVertex(int id);
	void addEdge(Edge *edge);
	void addEdge(Vertex *vertex1, Vertex *vertex2);
	void addEdge(Vertex *vertex1, Vertex *vertex2, int weight);
	void addEdge(int id1, int id2);
	void addEdge(int id1, int id2, int weight);
	void removeEdge(Edge *edge);
	void removeEdge(Vertex *vertex1, Vertex *vertex2);	
	void removeEdge(int id);
	void removeEdge(int id1, int id2);
	void outputEdges();	
	int getId();
	std::vector<Vertex> getVertexes();
	std::vector<Edge> getEdges();
	//virtual void Function();
};

