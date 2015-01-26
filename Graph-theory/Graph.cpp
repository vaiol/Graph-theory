#pragma once
#include "Graph.h"

//======= BEGIN ====================== private method ================================

bool Graph::hasVertex(int id)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].getId() == id)
		{
			return true;
		}
	}
	return false;
}

int Graph::firstVertex()
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].getId() != i+1)
		{
			return i+1;
		}
	}
	return vertices.size() + 1;
}


//======== END ======================= private method ================================

//======= BEGIN ====================== common method =================================

Graph::Graph()
{
}

Graph::~Graph()
{
}

Edge * Graph::getEdge(int id)
{
	return &edges.at(id);
}

Vertex * Graph::getVertex(int id)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].getId() == id)
		{
			return &vertices[i];
		}
	}
	return NULL;
}

bool Graph::addEdge(Edge * edge)
{
	if (hasEdge(edge))
		return false;
	if (!(hasVertex(edge->getVertex1()->getId()) && hasVertex(edge->getVertex1()->getId())))
		return false;

	edges.push_back(Edge(getVertex(edge->getVertex1()->getId()), getVertex(edge->getVertex2()->getId()), edge->getWeight()));
	update();
	return true;
}

bool Graph::addEdge(int vertex1, int vertex2, int weight)
{
	if (!(hasVertex(vertex1) && hasVertex(vertex2)))
		return false;
	Edge e(getVertex(vertex1), getVertex(vertex2), weight);
	if (hasEdge(&e))
		return false;
	edges.push_back(e);
	update();
	return true;
}

bool Graph::addEdge(int vertex1, int vertex2)
{
	if (!(hasVertex(vertex1) && hasVertex(vertex2)))
		return false;
	Edge e(getVertex(vertex1), getVertex(vertex2));
	if (hasEdge(&e))
		return false;
	edges.push_back(e);
	update();
	return true;
}

void Graph::addVertex()
{
	vertices.push_back(Vertex(firstVertex()));
	update();
}

void Graph::addVertex(int count)
{
	for (int i = 0; i < count; i++)
	{
		addVertex();
	}
	update();
}

void Graph::removeEdge(Edge * edge) 
{
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == *edge) {
			edges.erase(edges.begin() + i);
			i--;
		}
	}
	update();
}

void Graph::removeVertex(int id) 
{
	for (int i = 0; i < edges.size(); i++) 
	{
		if ((edges[i].getVertex1()->getId()) == id || (edges[i].getVertex2()->getId()) == id) 
		{
			edges.erase(edges.begin() + i);
			i--;
		}
	}
	vertices.erase(vertices.begin() + id);
	update();
}

void Graph::removeVertex(Vertex * vertex) 
{
	removeVertex(vertex->getId());
	update();
}

//----- BEGIN ----------------------- matrices ------------------------------------

void Graph::outputIncedenceMatrix()
{
	int line = vertices.size();
	int column = edges.size();
	std::cout << "     --- incedence matrix ---" << std::endl;
	std::cout << "    | ";
	for (int i = 0; i < column; i++)
	{
		std::cout << std::setw(2) << "e" << i + 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < column; i++)
	{
		std::cout << "----";
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << " v" << (i + 1) << " | ";
		for (int j = 0; j < column; j++)
		{
			std::cout << std::setw(3) << incedenceMatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Graph::outputAdjacencyMatrix()
{
	int line = vertices.size();
	std::cout << "     --- adjacency matrix ---" << std::endl;
	std::cout << "    | ";
	for (int i = 0; i < line; i++)
	{
		std::cout << std::setw(2) << "v" << i + 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << "----";
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << " v" << (i + 1) << " | ";
		for (int j = 0; j < line; j++)
		{
			std::cout << std::setw(3) << adjacencyMatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int ** Graph::getAdjacencyMatrix()
{
	return adjacencyMatrix;
}

int ** Graph::getIncedenceMatrix()
{
	return incedenceMatrix;
}

void Graph::update()
{
	incedenceMatrix = createIncedenceMatrix();
	adjacencyMatrix = createAdjacencyMatrix();
}

//------ END ------------------------ matrices --------------------------------------

std::ostream& operator<<(std::ostream &strm, const Graph & ag) 
{
	strm << "------- Graph ------" << std::endl;
	strm << "   EDGE    | VERTEX " << std::endl;
	strm << "--------------------" << std::endl;
	
	for (int i = 0; i < ag.edges.size(); i++) 
	{
		strm << ag.edges[i] << " | ";
		if (i < ag.vertices.size())
		{
			strm << " " << ag.vertices[i];
		}
		strm << std::endl;
	}
	return strm;
}

//=======  END  ====================== common method =================================


