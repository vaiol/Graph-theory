#pragma once
#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;




int main() {

	Graph * graph = new OrientedGraph();
	graph->addVertex(15);
	graph->addEdge(1, 2);
	graph->addEdge(1, 3);

	graph->addEdge(2, 4); 
	graph->addEdge(2, 5); 
	graph->addEdge(2, 6);

	graph->addEdge(3, 7);
	graph->addEdge(3, 8);
	graph->addEdge(3, 9);

	graph->addEdge(4, 10); 
	graph->addEdge(5, 11);

	graph->addEdge(7, 12);
	graph->addEdge(8, 13);

	graph->addEdge(11, 14);
	graph->addEdge(13, 15);

	graph->update();


	
	cout << *graph << endl;
	graph->outputAdjacencyMatrix();
	graph->outputReachabilityMatrix();
	Vertex v(1);
	graph->BFS(&v);
	





	cin.get();
	return 0;
	
}
