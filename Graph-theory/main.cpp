#include <iostream>
#include "OrientedGraph.h"
#include "NonOrientedGraph.h"

using namespace std;


void outputMatrix(Matrix matrix) 
{
	int line = matrix.line;
	int column = matrix.column;
	int ** m = matrix.matrix;

	cout << endl;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

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
	}
	cout << *graph << endl;

	Matrix matrix = graph->incedenceMatrix();
	outputMatrix(matrix);





	cin.get();
	return 0;
	
}
