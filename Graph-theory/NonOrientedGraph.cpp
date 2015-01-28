#pragma once
#include "NonOrientedGraph.h" 

NonOrientedGraph::NonOrientedGraph() : Graph() 
{
}

std::vector<std::vector<int>> NonOrientedGraph::createIncedenceMatrix()
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
				if ((edges[j].getVertex1()->getId()-1) == i)
					result[i][j] = 2;
				else 
					result[i][j] = 0;
			}
			else if (edges[j].getVertex1()->getId() == i + 1 || edges[j].getVertex2()->getId() == i + 1)
				result[i][j] = 1;
			else 
				result[i][j] = 0;
		}
	}

	return result;
}

std::vector<std::vector<int>> NonOrientedGraph::createAdjacencyMatrix()
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
			result[i][j] = 0;
	}

	//-----------create adjacency matrix
	for (int i = 0; i < column; i++)
	{
		int v1 = edges[i].getVertex1()->getId();
		int v2 = edges[i].getVertex2()->getId();
		if (v1 == v2)
		{
			result[v1 - 1][v2 - 1]++;
			continue;
		}
		result[v1-1][v2-1]++;
		result[v2-1][v1-1]++;
	}
	return result;
}

bool NonOrientedGraph::hasEdge(Edge * edge)
{
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].getVertex1() == edge->getVertex1() && edges[i].getVertex2() == edge->getVertex2()) 
		{
			if (edges[i].getWeight() == edge->getWeight())
				return true;
		}
		if (edges[i].getVertex1() == edge->getVertex2() && edges[i].getVertex2() == edge->getVertex1())
		{
			if (edges[i].getWeight() == edge->getWeight())
				return true;
		}
	}
	return false;
}

