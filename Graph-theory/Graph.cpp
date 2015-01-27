#pragma once
#include "Graph.h"

//======= BEGIN ====================== private method ================================

bool Graph::hasVertex(int id)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].getId() == id)
		{
			return true;
		}
	}
	return false;
}

int Graph::firstVertex()
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].getId() != i+1)
		{
			return i+1;
		}
	}
	return vertices.size() + 1;
}

int ** Graph::degreeMatrix(int ** matrix, int degree)
{
	//-------- declare and initialize the resulting matrix
	int vertexCount = vertices.size();
	int **result = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		result[i] = new int[vertexCount];
	}
	//-------- declare and initialize the intermediate matrix
	int **degreeMatrix = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		degreeMatrix[i] = new int[vertexCount];
	}
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = 0; j < vertexCount; j++)
		{
			degreeMatrix[i][j] = matrix[i][j];
		}
	}
	//--------- exponentiation matrix
	for (int deg = 1; deg < degree; deg++)
	{
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				int currentResult = 0;
				for (int k = 0; k < vertexCount; k++)
				{
					currentResult += degreeMatrix[i][k] * matrix[k][j];
				}
				result[i][j] = currentResult;
			}
		}
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				degreeMatrix[i][j] = result[i][j];
			}
		}
	}
	return result;

}

int ** Graph::createDistanceMatrix()
{
	int vertexCount = vertices.size();
	//--------- declare and initialize the resulting matrix 
	int **result = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		result[i] = new int[vertexCount];
	//--------- fiil an matrix 
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = 0; j < vertexCount; j++)
		{
			result[i][j] = adjacencyMatrix[i][j];
			if (adjacencyMatrix[i][j] == 0)
				result[i][j] = -1;
		}
	}
	//--------- fill diagonal matrix with zeros
	for (int i = 0; i < vertexCount; i++)
	{
		result[i][i] = 0;
	}
	//--------- create distance matrix
	int degree = 2;
	bool condition = true;
	while (condition)
	{
		int ** degMatrix = degreeMatrix(adjacencyMatrix, degree);
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				if (result[i][j] < 0)
				{
					if (degMatrix[i][j] > 0)
						result[i][j] = degree;
				}

			}
		}
		//-------- exit condition from the loop
		condition = false;
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				if (result[i][j] == -1)
					condition = true;

				if (degree > vertices.size())
					condition = false;
			}
		}
		degree++;
	}
	return result;
}

int ** Graph::createReachabilityMatrix()
{
	int vertexCount = vertices.size();
	//--------- declare and initialize the resulting matrix 
	int **result = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		result[i] = new int[vertexCount];
	//--------- fiil an matrix 
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = 0; j < vertexCount; j++)
		{
			result[i][j] = adjacencyMatrix[i][j];
		}
	}
	int degree = 2;
	bool condition = true;
	while (condition)
	{
		int ** degMatrix = degreeMatrix(adjacencyMatrix, degree);
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				if (result[i][j] == 0)
				{
					if (degMatrix[i][j] > 0)
						result[i][j] = 1;
				}

			}
		}
		//-------- exit condition from the loop
		if (degree >= vertices.size())
			condition = false;

		degree++;
	}
	return result;
}

void Graph::outputSquareMatrix(int ** matrix, int line)
{
	std::cout << "    | ";
	for (int i = 0; i < line; i++)
	{
		std::cout << std::setw(2) << "v" << i + 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << "----";
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << " v" << (i + 1) << " | ";
		for (int j = 0; j < line; j++)
		{
			std::cout << std::setw(3) << matrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//======== END ======================= private method ================================

//======= BEGIN ====================== common method =================================

Graph::Graph()
{
}

Graph::~Graph()
{
}

Edge * Graph::getEdge(int id)
{
	return &edges.at(id);
}

Vertex * Graph::getVertex(int id)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].getId() == id)
		{
			return &vertices[i];
		}
	}
	return NULL;
}

bool Graph::addEdge(Edge * edge)
{
	if (hasEdge(edge))
		return false;
	if (!(hasVertex(edge->getVertex1()->getId()) && hasVertex(edge->getVertex1()->getId())))
		return false;

	edges.push_back(Edge(getVertex(edge->getVertex1()->getId()), getVertex(edge->getVertex2()->getId()), edge->getWeight()));
	update();
	return true;
}

bool Graph::addEdge(int vertex1, int vertex2, int weight)
{
	if (!(hasVertex(vertex1) && hasVertex(vertex2)))
		return false;
	Edge e(getVertex(vertex1), getVertex(vertex2), weight);
	if (hasEdge(&e))
		return false;
	edges.push_back(e);
	update();
	return true;
}

bool Graph::addEdge(int vertex1, int vertex2)
{
	if (!(hasVertex(vertex1) && hasVertex(vertex2)))
		return false;
	Edge e(getVertex(vertex1), getVertex(vertex2));
	if (hasEdge(&e))
		return false;
	edges.push_back(e);
	update();
	return true;
}

void Graph::addVertex()
{
	vertices.push_back(Vertex(firstVertex()));
	update();
}

void Graph::addVertex(int count)
{
	for (int i = 0; i < count; i++)
	{
		addVertex();
	}
	update();
}

void Graph::removeEdge(Edge * edge) 
{
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == *edge) {
			edges.erase(edges.begin() + i);
			i--;
		}
	}
	update();
}

void Graph::removeVertex(int id) 
{
	for (int i = 0; i < edges.size(); i++) 
	{
		if ((edges[i].getVertex1()->getId()) == id || (edges[i].getVertex2()->getId()) == id) 
		{
			edges.erase(edges.begin() + i);
			i--;
		}
	}
	vertices.erase(vertices.begin() + id);
	update();
}

void Graph::removeVertex(Vertex * vertex) 
{
	removeVertex(vertex->getId());
	update();
}

//----- BEGIN ----------------------- matrices ------------------------------------

void Graph::outputIncedenceMatrix()
{
	int line = vertices.size();
	int column = edges.size();
	std::cout << "     --- incedence matrix ---" << std::endl;
	std::cout << "    | ";
	for (int i = 0; i < column; i++)
	{
		std::cout << std::setw(2) << "e" << i + 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < column; i++)
	{
		std::cout << "----";
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << " v" << (i + 1) << " | ";
		for (int j = 0; j < column; j++)
		{
			std::cout << std::setw(3) << incedenceMatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Graph::outputAdjacencyMatrix()
{
	std::cout << "     --- adjacency matrix ---" << std::endl;
	outputSquareMatrix(adjacencyMatrix, vertices.size());
}

void Graph::outputDistanceMatrix()
{
	//--------output--------------
	int line = vertices.size();
	std::cout << "     --- distance matrix ---" << std::endl;
	std::cout << "    | ";
	for (int i = 0; i < line; i++)
	{
		std::cout << std::setw(3) << "v" << i + 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << "-----";
	}
	std::cout << std::endl;
	for (int i = 0; i < line; i++)
	{
		std::cout << " v" << (i + 1) << " | ";
		for (int j = 0; j < line; j++)
		{
			if (distanceMatrix[i][j] == -1)
				std::cout << std::setw(4) << "inf";
			else
				std::cout << std::setw(4) << distanceMatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Graph::outputReachabilityMatrix()
{
	std::cout << "     --- reachability matrix ---" << std::endl;
	outputSquareMatrix(reachabilityMatrix, vertices.size());
}

int ** Graph::getAdjacencyMatrix()
{
	return adjacencyMatrix;
}

int ** Graph::getIncedenceMatrix()
{
	return incedenceMatrix;
}

int ** Graph::getDistanceMatrix()
{
	return distanceMatrix;
}

void Graph::update()
{
	incedenceMatrix = createIncedenceMatrix();
	adjacencyMatrix = createAdjacencyMatrix();
	distanceMatrix = createDistanceMatrix();
	reachabilityMatrix = createReachabilityMatrix();
}

//------ END ------------------------ matrices --------------------------------------

std::ostream& operator<<(std::ostream &strm, const Graph & ag) 
{
	strm << "------- Graph ------" << std::endl;
	strm << "   EDGE    | VERTEX " << std::endl;
	strm << "--------------------" << std::endl;
	int count;
	if (ag.edges.size() > ag.vertices.size())
	{
		count = ag.edges.size();
	}
	else
	{
		count = ag.vertices.size();
	}
	for (int i = 0; i < count; i++) 
	{
		if (i < ag.edges.size())
			strm << ag.edges[i] << " | ";
		else
			strm << "           | ";
		if (i < ag.vertices.size())
			strm << " " << ag.vertices[i];
		strm << std::endl;
	}
	return strm;
}

//=======  END  ====================== common method =================================


