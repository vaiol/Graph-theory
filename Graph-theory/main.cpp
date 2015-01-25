#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;




int main() {

	Graph * graph = new OrientedGraph();
	{
		Vertex v1(1);
		Vertex v2(2);
		graph->addVertex(6);
		graph->addEdge(&(Edge(&v1, &v2)));
		graph->addEdge(2, 3);
		graph->addEdge(2, 4);
		graph->addEdge(3, 4);
		graph->addEdge(3, 6);
		graph->addEdge(4, 5);
		graph->addEdge(5, 3);
		graph->addEdge(5, 6);
		graph->addEdge(6, 6);
	}
	cout << *graph << endl;

	Matrix matrix = graph->incedenceMatrix();
	matrix.outputMatrix();





	cin.get();
	return 0;
	
}
