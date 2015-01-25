#include "AbstractGraph.h"

AbstractGraph::AbstractGraph(Edge * edge){
	addEdge(edge);
}

AbstractGraph::~AbstractGraph(){}

Edge * AbstractGraph::getEdge(int id)
{
	return &edges.at(id);
}

void AbstractGraph::removeEdge(int id)
{
	edges.erase(edges.begin()+id);
}

void AbstractGraph::removeEdge(Edge * edge) 
{
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == *edge) {
			removeEdge(i);
			i--;
		}
	}
}

void AbstractGraph::removeVertex(int id) 
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

void AbstractGraph::removeVertex(Vertex * vertex) 
{
	removeVertex(vertex->getId());
}

void AbstractGraph::addEdge(Edge * edge) 
{
	edges.push_back(*edge);
}

std::ostream& operator<<(std::ostream &strm, const AbstractGraph & ag) {
	/*strm << "Graph {" << std::endl;
	for (int i = 0; i < ag.edges.size(); i++) {
		strm << "   " << ag.edges[i] << std::endl;
	}
	strm << "}";*/
	return strm;
}
