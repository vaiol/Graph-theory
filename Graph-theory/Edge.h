#pragma once 
#include "Vertex.h"

class Edge
{
private:
	Vertex *vertex1;
	Vertex *vertex2;
	int weight;
public:
	Edge(Vertex * vertex1, Vertex * vertex2, int weight);
	Edge(Vertex * vertex1, Vertex * vertex2);
	Edge(Vertex * vertex, int weight);
	Edge(Vertex * vertex);
	~Edge();
	Vertex * getVertex1();
	Vertex * getVertex2();
	int getWeight();
	void setVertex1(Vertex * vertex1);
	void setVertex2(Vertex * vertex2);
	void setWeight(int weight);	
	friend bool operator==(const Edge& left, const Edge& right);
	friend std::ostream& operator<<(std::ostream&, const Edge&);
};
