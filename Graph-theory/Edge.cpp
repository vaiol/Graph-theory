#pragma once
#include "Edge.h"

Edge::Edge(Vertex * vertex1, Vertex * vertex2, int weight)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->weight = weight;
}

Edge::Edge(Vertex * vertex1, Vertex * vertex2)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->weight = 0;
}

Edge::Edge(Vertex * vertex, int weight) 
{
	this->vertex1 = vertex;
	this->vertex2 = vertex;
	this->weight = weight;
}

Edge::Edge(Vertex * vertex)
{
	this->vertex1 = vertex;
	this->vertex2 = vertex;
	this->weight = 0;
}

Edge::~Edge()
{

}

Vertex * Edge::getVertex1()
{
	return vertex1;
}

Vertex * Edge::getVertex2()
{
	return vertex2;
}

int Edge::getWeight()
{
	return weight;
}

void Edge::setVertex1(Vertex * vertex1)
{
	this->vertex1 = vertex1;
}

void Edge::setVertex2(Vertex * vertex2)
{
	this->vertex2 = vertex2;
}

void Edge::setWeight(int weight)
{
	this->weight = weight;
}

bool operator==(const Edge& left, const Edge& right) {

	if (!(*left.vertex1 == *right.vertex1))
	{
		return false;
	}
	if (!(*left.vertex2 == *right.vertex2))
	{
		return false;
	}
	if (!(left.weight == right.weight))
	{
		return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream &strm, const Edge & edge) {
	return strm << std::setw(2) << *edge.vertex1 << " -" << std::setw(2) << *edge.vertex2 << " |" << std::setw(2) << edge.weight;
}