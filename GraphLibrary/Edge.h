#pragma once
#include "Vertex.h"
class Edge
{
private:
	Vertex *vertex1;
	Vertex *vertex2;
	int weight;   
public:
	Edge();	
	Edge(Vertex *vertex);
	Edge(Vertex *vertex, int weight);
	Edge(Vertex *vertex1, Vertex *vertex2);	
	Edge(Vertex *vertex1, Vertex *vertex2, int weight);	
	~Edge();
	void setWeight(int weight);
	Vertex *getVertex1();
	Vertex *getVertex2();
	int getWeight();	
};

