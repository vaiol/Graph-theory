#pragma once
#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;




int main() {

	Graph * graph = new OrientedGraph();
	graph->addVertex(4);
	graph->addEdge(1, 2);
	graph->addEdge(2, 3);
	graph->addEdge(3, 1);
	graph->addEdge(4, 3);


	
	cout << *graph << endl;
	graph->outputReachabilityMatrix();
	graph->outputConnectivity();





	cin.get();
	return 0;
	
}
