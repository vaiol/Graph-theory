#include "Edge.h"


Edge::Edge()
{
}

Edge::Edge(Vertex *vertex)
{
	vertex1 = vertex;
	vertex2 = vertex;
	weight = 0;
}

Edge::Edge(Vertex *vertex, int weight)
{
	vertex1 = vertex;
	vertex2 = vertex;
	setWeight(weight);
}

Edge::Edge(Vertex *vertex1, Vertex *vertex2)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	weight = 0;
}

Edge::Edge(Vertex *vertex1, Vertex *vertex2, int weight)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	setWeight(weight);
}

Edge::~Edge()
{
}


void Edge::setWeight(int weight)
{
	this->weight = weight;
}

int Edge::getWeight()
{
	return weight;
}

Vertex *Edge::getVertex1()
{
	return vertex1;
}

Vertex *Edge::getVertex2()
{
	return vertex2;
}


	