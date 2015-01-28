#pragma once
#include "Vertex.h"

Vertex::Vertex(int id)
{
	this->id = id;
}

Vertex::~Vertex()
{

}

int Vertex::getId()
{
	return id;
}

void Vertex::setId(int id)
{
	this->id = id;
}

bool operator==(const Vertex& left, const Vertex& right) {
	return left.id == right.id;
}

std::ostream& operator<<(std::ostream &strm, const Vertex& vertex) {
	return strm  << std::setw(2) << vertex.id;
}