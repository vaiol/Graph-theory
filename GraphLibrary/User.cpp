#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph *g1 = new Graph();
	/*g1->addVertex(5);
	g1->addVertex(new Vertex(1));
	g1->outputVertexes();
	cout << endl;
	g1->removeVertex(1);
	g1->outputVertexes();
	cout << endl;
	g1->addVertex(3);
	g1->addVertex(2);
	g1->addVertex(7);	
	g1->outputVertexes();
	cout << endl;*/
	g1->addVertex(1);
	g1->addVertex(2);
	g1->outputVertexes();	
	g1->addEdge(new Vertex(3), new Vertex(4));
	g1->addEdge(new Vertex(3), new Vertex(4));
	g1->addEdge(new Vertex(3), new Vertex(4));
	g1->outputVertexes();
	g1->addEdge(1, 2);
	g1->addEdge(1, 2);
	g1->addEdge(3, 5);	
	g1->outputVertexes();
	

	getchar();
	return 0;
}