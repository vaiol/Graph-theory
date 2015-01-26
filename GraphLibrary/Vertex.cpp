#include "Vertex.h"

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
}

Vertex::Vertex(int id)
{
	setId(id);
}

int Vertex::getId()
{
	return id;
}
void Vertex::setId(int id)
{
	this->id = id;
}

