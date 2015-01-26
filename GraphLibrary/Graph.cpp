#include "Graph.h"
#include <iostream>

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::setId(int id)
{
	this->id = id;
}

void  Graph::addVertex(Vertex *vertex)
{	
	if (checkVertex(vertex) == false)
	vertexes.push_back(*vertex);
}

void  Graph::addVertex(int id)
{
	if (checkVertex(id) == false)
	{
		Vertex *vertex = new Vertex(id);
		vertexes.push_back(*vertex);
	}	
}

void  Graph::removeVertex(Vertex *vertex)
{
	if (checkVertex(vertex) == true)
	&vertexes.erase(vertexes.begin() + vertex->getId());
}

void  Graph::removeVertex(int id)
{
	if (checkVertex(id) == true)
	&vertexes.erase(vertexes.begin() + id);
}

std::vector<Vertex> Graph::getVertexes()
{
	return vertexes;
}

void Graph::outputVertexes()
{
	std::vector<Vertex> vertexes = this->getVertexes();
	for (int i = 0; i < vertexes.size(); i++)
	{
		std::cout << vertexes[i].getId() << " ";
	}
	std::cout << std::endl;
}

bool Graph::checkVertex(Vertex *vertex)
{
	return checkVertex(vertex->getId());
}

bool Graph::checkVertex(int id)
{
	bool check = false;
	for (int i = 0; i < vertexes.size(); i++)
	{
		if ((&vertexes[i])->getId() == id)
		{
			check = true;
			break;
		}
	}
	return check;
}


void  Graph::addEdge(Edge *edge)
{
	edges.push_back(*edge);
	std::cout << "Edge (" << edge->getVertex1()->getId() << ", " <<
		edge->getVertex2()->getId() << ") was added" << std::endl;
}

void  Graph::addEdge(Vertex *vertex1, Vertex *vertex2, int weight)
{
	Edge *edge = new Edge(vertex1, vertex2);
	edges.push_back(*edge);
	if (checkVertex(vertex1) == false || checkVertex(vertex2) == false)
	{
		addVertex(vertex1);
		addVertex(vertex2);
	}
	edge->setWeight(weight);
	std::cout << "Edge (" << vertex1->getId() << ", " << vertex2->getId() << ") was added" << std::endl;
}

void  Graph::addEdge(Vertex *vertex1, Vertex *vertex2)
{
	addEdge(vertex1, vertex2, 0);
}

void  Graph::addEdge(int id1, int id2, int weight)
{
	Edge *edge = new Edge();
	if (checkVertex(id1) == false || checkVertex(id2) == false)
	{
		addVertex(id1);
		addVertex(id2);
	}
	edges.push_back(*edge);
	edge->setWeight(weight);
	std::cout << "Edge (" << id1 << ", " << id2 << ") was added" << std::endl;
}

void  Graph::addEdge(int id1, int id2)
{
	addEdge(id1, id2, 0);
}

/*void  Graph::removeEdge(Edge *edge)
{
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i] == *edge)
	}
	std::cout << "Edge (" << edge->getVertex1()->getId() << ", " <<
		edge->getVertex2()->getId() << ") was added" << std::endl;
}*/

void  Graph::removeEdge(int id)
{

}

void  Graph::removeEdge(int id1, int id2)
{

}

/*int  Graph::getId()
{

}
*/