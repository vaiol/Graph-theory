#pragma once
#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;




int main() {

	Graph * graph = new OrientedGraph();
	graph->addVertex(3);
	graph->addEdge(1, 2);
	graph->addEdge(2, 3);
	graph->addEdge(3, 1);


	
	cout << *graph << endl;
	graph->outputIncedenceMatrix();
	graph->outputAdjacencyMatrix();
	graph->outputDistanceMatrix();
	graph->outputReachabilityMatrix();
	graph->outputDegreeOfVertices();
	std::cout << std::endl;
	graph->outputIsolatedAndHangingVertices();





	cin.get();
	return 0;
	
}
