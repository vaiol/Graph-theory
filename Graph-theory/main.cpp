#pragma once
#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;




int main() {

	Graph * graph = new NonOrientedGraph();
	graph->addVertex(5);
	graph->addEdge(1, 2);
	graph->addEdge(2, 3);
	//graph->addEdge(3, 1);
	graph->addEdge(4, 3);


	
	cout << *graph << endl;
	graph->outputAdjacencyMatrix();
	graph->outputReachabilityMatrix();
	graph->outputConnectivity();
	if (graph->hasCycle())
		cout << "Graph has a cycle!" << endl;
	else
		cout << "Graph hasn't a cycle!" << endl;





	cin.get();
	return 0;
	
}
