#pragma once
#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;




int main() {

	Graph * graph = new NonOrientedGraph();
	graph->addVertex(6);
	graph->addEdge(1, 2);
	graph->addEdge(2, 3);
	graph->addEdge(3, 4);
	graph->addEdge(4, 5);
	graph->addEdge(5, 6);
	
	cout << *graph << endl;
	graph->outputAdjacencyMatrix();
	graph->outputDistanceMatrix();
	graph->outputReachabilityMatrix();





	cin.get();
	return 0;
	
}
