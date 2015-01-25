#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"
#include "Edge.h"
#include "Vertex.h"

using namespace std;

int main() {
	Vertex v(10);
	Vertex v1(8);
	Vertex v2(7);
	Edge e(&v);
	Edge e1(&v1);
	Edge e2(&v2);
	

	Graph * a = new OrientedGraph(&e);
	Graph * b = new NonOrientedGraph(&e);
	a->addEdge(&e);
	a->addEdge(&e);
	a->addEdge(&e);
	a->addEdge(&e1);
	a->addEdge(&e2);

	cout << *a;

	cout << endl << endl;

	a->removeVertex(&v);

	cout << *a << endl;
	cout << *b;
	a->removeThisMethodInTheFuture();
	b->removeThisMethodInTheFuture();

	cin.get();
	return 0;
	
}