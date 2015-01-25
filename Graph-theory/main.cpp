#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"
#include "Edge.h"
#include "Vertex.h"

using namespace std;

int main() {

	Graph * graph = new OrientedGraph();
	{
		Vertex v1(1);
		Vertex v2(2);
		graph->addVertex(6);
		graph->addEdge(&(Edge(&v1, &v2)));
		graph->addEdge(2, 3, 2);
		graph->addEdge(2, 4, 2);
		graph->addEdge(3, 4, 2);
		graph->addEdge(3, 6, 2);
		graph->addEdge(4, 5, 2);
		graph->addEdge(5, 3, 2);
		graph->addEdge(5, 6, 2);
	}
	cout << *graph << endl;




	cin.get();
	return 0;
	
}