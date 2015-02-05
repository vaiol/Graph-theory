#pragma once
#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;




int main() {

	Graph * graph = new OrientedGraph();
	graph->addVertex(8);
	graph->addEdge(1, 2);
	graph->addEdge(1, 3);

	graph->addEdge(2, 3);
	graph->addEdge(2, 4); 
	graph->addEdge(2, 5); 
	graph->addEdge(2, 6);

	graph->addEdge(3, 7);
	graph->addEdge(4, 8);
	graph->addEdge(5, 8);

	graph->update();


	
	cout << *graph << endl;
	graph->outputAdjacencyMatrix();
	graph->outputReachabilityMatrix();
	Vertex v(1);
	graph->BFS(&v);
	





	cin.get();
	return 0;
	
}
