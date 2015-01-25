#include "Graph.h"

Graph::Graph(Edge * edge)
{
	addEdge(edge);
}



Edge * Graph::getEdge(int id)
{
	return &edges.at(id);
}

void Graph::removeEdge(int id)
{
	edges.erase(edges.begin()+id);
}

void Graph::removeEdge(Edge * edge) 
{
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == *edge) {
			removeEdge(i);
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
			removeEdge(i);
			i--;
		}
	}
}

void Graph::removeVertex(Vertex * vertex) 
{
	removeVertex(vertex->getId());
}

void Graph::addEdge(Edge * edge) 
{
	edges.push_back(*edge);
}

std::ostream& operator<<(std::ostream &strm, const Graph & ag) 
{
	strm << "Graph {" << std::endl;
	for (int i = 0; i < ag.edges.size(); i++) {
		strm << "   " << ag.edges[i] << std::endl;
	}
	strm << "}";
	return strm;
}

