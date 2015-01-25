#include <iostream>
#include "AbstractGraph.h"
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
	

	AbstractGraph a(&e);
	a.addEdge(&e);
	a.addEdge(&e);
	a.addEdge(&e);
	a.addEdge(&e1);
	a.addEdge(&e2);

	cout << a;

	cout << endl << endl;

	a.removeVertex(&v);

	cout << a;

	cin.get();
	return 0;
	
}