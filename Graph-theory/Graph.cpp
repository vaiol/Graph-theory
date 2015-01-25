#include "Graph.h"

//======= BEGIN ====================== private method ================================

bool Graph::hasVertex(int id)
{
	for (int i = 0; i < vertex.size(); i++)
	{
		if (vertex[i].getId() == id)
		{
			return true;
		}
	}
	return false;
}

int Graph::firstVertex()
{
	for (int i = 0; i < vertex.size(); i++)
	{
		if (vertex[i].getId() != i+1)
		{
			return i+1;
		}
	}
	return vertex.size()+1;
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
	for (int i = 0; i < vertex.size(); i++)
	{
		if (vertex[i].getId() == id)
		{
			return &vertex[i];
		}
	}
	return NULL;
}

void Graph::addEdge(Edge * edge)
{
	Edge e(edge->getVertex1(), edge->getVertex2(), edge->getWeight());
	if (hasVertex(edge->getVertex1()->getId()) && hasVertex(edge->getVertex2()->getId()))
	{
		edges.push_back(e);
	}
}

void Graph::addEdge(int vertex1, int vertex2, int weight)
{
	if (hasVertex(vertex1) && hasVertex(vertex2))
	{
		Vertex * v1 = getVertex(vertex1);
		Vertex * v2 = getVertex(vertex2);
		edges.push_back(Edge(v1, v2, weight));
	}
}

void Graph::addEdge(int vertex1, int vertex2)
{
	if (hasVertex(vertex1) && hasVertex(vertex2))
	{
		Vertex * v1 = getVertex(vertex1);
		Vertex * v2 = getVertex(vertex2);
		edges.push_back((Edge(v1, v2)));
	}
}

void Graph::addVertex()
{
	vertex.push_back(Vertex(firstVertex()));
}

void Graph::addVertex(int count)
{
	for (int i = 0; i < count; i++)
	{
		addVertex();
	}
}

void Graph::removeEdge(Edge * edge) 
{
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == *edge) {
			edges.erase(edges.begin() + i);
			i--;
		}
	}
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
	vertex.erase(vertex.begin() + id);
}

void Graph::removeVertex(Vertex * vertex) 
{
	removeVertex(vertex->getId());
}

std::ostream& operator<<(std::ostream &strm, const Graph & ag) 
{
	strm << "Graph {" << std::endl;
	for (int i = 0; i < ag.edges.size(); i++) 
	{
		strm << "   " << ag.edges[i] << std::endl;
	}
	for (int i = 0; i < ag.vertex.size(); i++)
	{
		strm << "Vertex" << ag.vertex[i] << std::endl;
	}
	strm << "}";
	return strm;
}

//=======  END  ====================== common method =================================

//====== BEGIN ===================== incedence matrix ================================



//======  END  ===================== incedence matrix ================================

