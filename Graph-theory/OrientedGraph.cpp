#include "OrientedGraph.h" 

OrientedGraph::OrientedGraph() : Graph() {}

Matrix OrientedGraph::incedenceMatrix()
{
	
	size_t line = vertex.size();
	size_t column = edges.size();
	
	int **matrix = new int*[line];
	for (int i = 0; i < vertex.size(); i++)
	{
		matrix[i] = new int[column];
	}
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (edges[j].getVertex1()->getId() == edges[j].getVertex2()->getId())
			{
				if ((edges[j].getVertex1()->getId() - 1) == i)
				{
					matrix[i][j] = 2;
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
			else if (edges[j].getVertex1()->getId() == i + 1)
			{
				matrix[i][j] = -1;
			}
			else if (edges[j].getVertex2()->getId() == i+1)
			{
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	Matrix result
	{
		matrix,
		line,
		column
	};
	return result;
}