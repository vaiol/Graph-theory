#pragma once
#include "OrientedGraph.h" 

OrientedGraph::OrientedGraph() : Graph()
{
}

std::vector<std::vector<int>> OrientedGraph::createIncedenceMatrix()
{
	
	size_t line = vertices.size();
	size_t column = edges.size();
	
	//-----------declare the resulting matrix
	std::vector<std::vector<int>> result(line);

	//-----------create incedence matrix
	for (int i = 0; i < line; i++)
	{
		result[i].resize(column); //initialize the resulting matrix
		for (int j = 0; j < column; j++)
		{
			if (edges[j].getVertex1()->getId() == edges[j].getVertex2()->getId())
			{
				if ((edges[j].getVertex1()->getId() - 1) == i)
					result[i][j] = 2;
				else
					result[i][j] = 0;
			}
			else if (edges[j].getVertex1()->getId() == i + 1)
				result[i][j] = -1;
			else if (edges[j].getVertex2()->getId() == i+1)
				result[i][j] = 1;
			else 
				result[i][j] = 0;
		}
	}
	return result;
}

std::vector<std::vector<int>> OrientedGraph::createAdjacencyMatrix()
{
	size_t line = vertices.size();
	size_t column = edges.size();

	//-----------declare the resulting matrix
	std::vector<std::vector<int>> result(line);

	//-----------initialize the resulting matrix
	for (int i = 0; i < line; i++)
	{
		result[i].resize(line);
		for (int j = 0; j < line; j++)
		{
			result[i][j] = 0;
		}
	}
	//-----------create adjacency matrix
	for (int i = 0; i < column; i++)
	{
		int v1 = edges[i].getVertex1()->getId();
		int v2 = edges[i].getVertex2()->getId();

		result[v1 - 1][v2 - 1]++;
	}

	return result;
}

bool OrientedGraph::hasEdge(Edge * edge)
{
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i] == *edge)
			return true;
	}
	return false;
}
