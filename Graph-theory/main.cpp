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

	graph->addEdge(2, 5);
	graph->addEdge(2, 7); 
	graph->addEdge(2, 8); 

	graph->addEdge(3, 4);
	graph->addEdge(5, 6);
	graph->addEdge(7, 6);

	graph->update();


	
	cout << *graph << endl;
	graph->outputAdjacencyMatrix();
	graph->outputReachabilityMatrix();
	graph->DFS(1);

	





	cin.get();
	return 0;
	
}
