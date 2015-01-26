#pragma once
#include "OrientedGraph.h" 

OrientedGraph::OrientedGraph() : Graph()
{
}

int ** OrientedGraph::createIncedenceMatrix()
{
	
	size_t line = vertices.size();
	size_t column = edges.size();
	
	//-----------declare and initialize an array
	int **matrix = new int*[line];
	for (int i = 0; i < line; i++)
	{
		matrix[i] = new int[column];
	}

	//-----------create incedence matrix
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

	return matrix;
}

int ** OrientedGraph::createAdjacencyMatrix()
{
	size_t line = vertices.size();
	size_t column = edges.size();

	//-----------declare and initialize an array
	int **matrix = new int*[line];
	for (int i = 0; i < line; i++)
	{
		matrix[i] = new int[column];
	}

	//-----------fill an array
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = 0;
		}
	}

	//-----------create adjacency matrix
	for (int i = 0; i < column; i++)
	{
		int v1 = edges[i].getVertex1()->getId();
		int v2 = edges[i].getVertex2()->getId();

		matrix[v1 - 1][v2 - 1]++;
	}

	return matrix;
}

bool OrientedGraph::hasEdge(Edge * edge)
{
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i] == *edge)
		{
			return true;
		}
	}
	return false;
}
