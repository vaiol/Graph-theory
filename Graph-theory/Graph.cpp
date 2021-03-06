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

std::vector<std::vector<int>> Graph::degreeMatrix(std::vector<std::vector<int>> matrix, int degree)
{
	int vertexCount = vertices.size();
	//-------- declare the resulting matrix
	std::vector<std::vector<int>> result(vertexCount);

	//-------- declare and initialize the intermediate matrix
	std::vector<std::vector<int>> degreeMatrix(vertexCount);

	for (int i = 0; i < vertexCount; i++)
	{
		result[i].resize(vertexCount); //initialize the resulting matrix
		degreeMatrix[i].resize(vertexCount); //initialize intermediate matrix
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

std::vector<std::vector<int>> Graph::createDistanceMatrix()
{
	int vertexCount = vertices.size();
	//--------- declare the resulting matrix 
	std::vector<std::vector<int>> result(vertexCount);
	//--------- fiil an matrix 
	for (int i = 0; i < vertexCount; i++)
	{
		result[i].resize(vertexCount); // declare the resulting matrix 
		for (int j = 0; j < vertexCount; j++)
		{
			result[i][j] = adjacencyMatrix[i][j];
			if (adjacencyMatrix[i][j] == 0)
				result[i][j] = -1;
		}
		result[i][i] = 0; //fill diagonal matrix with zeros
	}

	//--------- create distance matrix
	int degree = 2;
	bool condition = true;
	while (condition)
	{
		std::vector<std::vector<int>>  degMatrix = degreeMatrix(adjacencyMatrix, degree);
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				if (result[i][j] < 0 && degMatrix[i][j] > 0)
				{
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

std::vector<std::vector<int>> Graph::createReachabilityMatrix()
{
	int vertexCount = vertices.size();
	//--------- declare the resulting matrix 
	std::vector<std::vector<int>> result(vertexCount);
		
	//--------- fiil an matrix 
	for (int i = 0; i < vertexCount; i++)
	{
		result[i].resize(vertexCount); 
		for (int j = 0; j < vertexCount; j++)
		{
			result[i][j] = adjacencyMatrix[i][j];
		}
	}
	int degree = 2;
	bool condition = true;
	while (condition)
	{
		std::vector<std::vector<int>> degMatrix = degreeMatrix(adjacencyMatrix, degree);
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				if (result[i][j] == 0 && degMatrix[i][j] > 0)
				{
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

void Graph::outputSquareMatrix(std::vector<std::vector<int>> matrix, int line)
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

std::vector<std::vector<int>> Graph::transposeMatrix(std::vector<std::vector<int>> matrix)
{
	std::vector<std::vector<int>> result(matrix[0].size());
	for (int i = 0; i < result.size(); i++)
		result[i].resize(matrix.size());

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			result[j][i] = matrix[i][j];
		}
	}
	return result;
}

std::vector<std::vector<int>> Graph::concatenationMatrices(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2)
{
	std::vector<std::vector<int>> result(matrix1.size());
	for (int i = 0; i < result.size(); i++)
	{
		result[i].resize(matrix1[i].size());
		for (int j = 0; j < result[i].size(); j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return result;
}

//======== END ======================= private method ================================

//======= BEGIN ====================== common method =================================

Graph::Graph()
{
}

Graph::Graph(Graph * graph)
{
	this->vertices = graph->vertices;
	this->edges = graph->edges;
	update();
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
	//update();
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
	//update();
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
	//update();
	return true;
}

void Graph::addVertex()
{
	vertices.push_back(Vertex(firstVertex()));
	//update();
}

void Graph::addVertex(int count)
{
	for (int i = 0; i < count; i++)
	{
		addVertex();
	}
	//update();
}

void Graph::removeEdge(Edge * edge) 
{
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == *edge) {
			edges.erase(edges.begin() + i);
			i--;
		}
	}
	//update();
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
	//update();
}

void Graph::removeVertex(Vertex * vertex) 
{
	removeVertex(vertex->getId());
	//update();
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

std::vector<std::vector<int>> Graph::getAdjacencyMatrix()
{
	return adjacencyMatrix;
}

std::vector<std::vector<int>> Graph::getIncedenceMatrix()
{
	return incedenceMatrix;
}

std::vector<std::vector<int>> Graph::getDistanceMatrix()
{
	return distanceMatrix;
}

std::vector<std::vector<int>> Graph::getReachabilityMatrix()
{
	return reachabilityMatrix;
}

void Graph::update()
{
	incedenceMatrix = createIncedenceMatrix();
	adjacencyMatrix = createAdjacencyMatrix();
	distanceMatrix = createDistanceMatrix();
	reachabilityMatrix = createReachabilityMatrix();
}

//------ END ------------------------ matrices --------------------------------------

//----- BEGIN ---------------------- properties -------------------------------------


int Graph::isHomogeneousGraph()
{
	std::vector<std::vector<int>> tmp = getDegreeOfVertices();
	int degree = tmp[0][0];
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i][0] != degree)
			return -1;
	}
	return degree;
}

bool Graph::isStronglyConnectedGraph()
{
	std::vector<std::vector<int>> matrix = getReachabilityMatrix();
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] != 1)
				return false;
		}
	}
	return true;
}

bool Graph::isUnilaterallyConnectedGraph()
{
	if (isStronglyConnectedGraph())
		return true;
	std::vector<std::vector<int>> matrix = getReachabilityMatrix();
	matrix = concatenationMatrices(matrix, transposeMatrix(matrix));
	for (int i = 0; i < matrix.size(); i++)
		matrix[i][i] = 1;


	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] < 1)
				return false;
		}
	}
	return true;

	
}

bool Graph::isWeaklyConnectedGraph()
{
	if (isStronglyConnectedGraph())
		return true;
	if (isUnilaterallyConnectedGraph())
		return true;
	
	std::vector<std::vector<int>> matrix = getAdjacencyMatrix();
	matrix = concatenationMatrices(matrix, transposeMatrix(matrix));
	for (int i = 0; i < matrix.size(); i++)
		matrix[i][i] = 1;
	matrix = degreeMatrix(matrix, matrix.size());
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0)
				return false;
		}
	}
	return true;

}

bool Graph::isDisconnectedGraph()
{
	if (isStronglyConnectedGraph())
		return false;
	if (isWeaklyConnectedGraph())
		return false;
	if (isUnilaterallyConnectedGraph())
		return false;
	return true;
}

void Graph::outputConnectivity()
{
	if (isStronglyConnectedGraph())
		std::cout << std::endl << "This graph is strongly connected!" << std::endl;
	else if (isUnilaterallyConnectedGraph())
		std::cout << std::endl << "This graph is unilaterally connected!" << std::endl;
	else if (isWeaklyConnectedGraph())
		std::cout << std::endl << "This graph is weakly connected!" << std::endl;
	else if (isDisconnectedGraph())
		std::cout << std::endl << "This graph is disconnected!" << std::endl;
	else
		std::cout << std::endl << "ERROR!!! (outputConnectivity())" << std::endl;
}

bool Graph::hasCycle()
{
	for (int i = 0; i < reachabilityMatrix.size(); i++)
	{
		if (reachabilityMatrix[i][i] > 0)
			return true;
	}
	return false;
}

std::vector<std::vector<int>> Graph::getDegreeOfVertices()
{
	std::vector<std::vector<int>> result(vertices.size());

	for (int i = 0; i < vertices.size(); i++)
	{
		result[i].resize(3);
		for (int j = 0; j < edges.size(); j++)
		{
			if (*(edges[j].getVertex1()) == vertices[i])
			{
				result[i][1]++; //output degree of vertices
				result[i][0]++; //common degree of vertices
			}
			if (*(edges[j].getVertex2()) == vertices[i])
			{
				result[i][2]++; //input degree of vertices
				result[i][0]++; //common degree of vertices
			}
		}
	}
	return result;
}

std::vector<Vertex> Graph::getIsolatedVertices()
{
	std::vector<Vertex> result;
	for (int i = 0; i < vertices.size(); i++)
	{
		bool condition = true;
		for (int j = 0; j < edges.size(); j++)
		{
			if (edges[j].getVertex1() == &vertices[i] || edges[j].getVertex2() == &vertices[i])
				condition = false;
		}
		if (condition)
			result.push_back(vertices[i]);
	}
	return result;
}

std::vector<Vertex> Graph::getHangingVertices()
{
	std::vector<Vertex> result;
	for (int i = 0; i < vertices.size(); i++)
	{
		bool b1 = true;
		bool b2 = true;
		for (int j = 0; j < edges.size(); j++)
		{
			if (edges[j].getVertex1() == &vertices[i])
				b1 = false;
			if (edges[j].getVertex2() == &vertices[i])
				b2 = false;

		}
		if ((!b1 && b2) || (b1 && !b2))
			result.push_back(vertices[i]);
	}
	return result;
}

void Graph::outputDegreeOfVertices()
{
	std::vector<std::vector<int>> degreeOfVertices = getDegreeOfVertices();

	std::cout << "----degree of vertices----" << std::endl;
	std::cout << " vertex | degree ( I | O )" << std::endl;
	std::cout << "--------|-----------------" << std::endl;
	for (int i = 0; i < degreeOfVertices.size(); i++)
	{
		std::cout << std::setw(5) << vertices[i].getId() << "   |";
		std::cout << std::setw(5) << degreeOfVertices[i][0] << "   (";
		std::cout << std::setw(2) << degreeOfVertices[i][2] << " |";
		std::cout << std::setw(2) << degreeOfVertices[i][1] << " )";
		std::cout << std::endl;
	}
	int degreeOfGraph = isHomogeneousGraph();
	if (degreeOfGraph > 0)
		std::cout << " + Graph is homogeneous! \n  + Degree of graph: " << degreeOfGraph << std::endl;
	else
		std::cout << " + Graph isn't homogeneous!" << std::endl;
}

void Graph::outputIsolatedAndHangingVertices()
{
	std::vector<Vertex> isolated = getIsolatedVertices();
	std::vector<Vertex> hanging = getHangingVertices();

	std::cout << "--outcasts vertices--" << std::endl;
	std::cout << " Isolated |  Hanging " << std::endl;
	std::cout << "----------|----------" << std::endl;
	int maxSize = 0;
	if (isolated.size() > hanging.size())
		maxSize = isolated.size();
	else
		maxSize = hanging.size();

	for (int i = 0; i < maxSize; i++)
	{
		if (isolated.size() > i)
			std::cout << std::setw(6) << isolated[i].getId() << "    |";
		else
			std::cout << "          |";
		if (hanging.size() > i)
			std::cout << std::setw(6) << hanging[i].getId();
		std::cout << std::endl;
	}
}

//------ END ----------------------- properties -------------------------------------

//----- BEGIN ---------------------- algorithms -------------------------------------

void Graph::outputPath(int start, int end)
{
	std::cout << " PATH " << start << " - " << end << ": ";
	if (!hasPath(start, end))
		std::cout << "not found." << std::endl;
	else
	{
		std::vector<int> path = getPathBFS(start, end);
		for (int i = 0; i < path.size()-1; i++)
		{
			std::cout << path[i] << " - ";
		}
		std::cout << path[path.size() - 1];
		std::cout << " (Length: " << getLengthPath(start, end) << ");" << std::endl;

	}
}

bool Graph::hasPath(int start, int end)
{
	if (!hasVertex(start) || !hasVertex(end)) // chech error
		return false;;

	if (reachabilityMatrix[start - 1][end - 1] > 0)
		return true;
	return false;
}

int Graph::getLengthPath(int start, int end)
{
	if (!hasPath(start, end))
		return -1;
	return distanceMatrix[start - 1][end  - 1];
}

//---BFS
void Graph::BFS(int startVertex)
{
	if (!hasVertex(startVertex))
	{ // chech error
		std::cout << " !!! BFS bypassing is not available!" << std::endl;
		return;
	}

	std::vector<int> queue;
	std::vector<bool> used(vertices.size() + 1);
	std::vector<int> parent(vertices.size() + 1);
	std::vector<int> pathLength(vertices.size() + 1);

	queue.push_back(startVertex);
	used[startVertex] = true;
	parent[startVertex] = -1;

	//output:
	int countOfCurrentVertex = 0;
	{
		countOfCurrentVertex++;
		std::cout << " VERTEX | BFS count |  QUEUE    " << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::setw(5) << startVertex << "   |" << std::setw(6) << countOfCurrentVertex << "     |  ";
		for (int i = 0; i < queue.size(); i++)
		{
			std::cout << queue[i] << " ";
		}
		std::cout << std::endl;
	}

	while (!queue.empty())
	{
		int currentVertex = queue.front();

		for (size_t i = 0; i< adjacencyMatrix[currentVertex - 1].size(); i++)
		{
			int someVertex = i + 1;
			if (adjacencyMatrix[currentVertex - 1][i] > 0 && !used[someVertex])
			{
				used[someVertex] = true;
				queue.push_back(someVertex);
				pathLength[someVertex] = pathLength[currentVertex] + 1;
				parent[someVertex] = currentVertex;
				{ //output:
					countOfCurrentVertex++;
					std::cout << std::setw(5) << someVertex << "   |" << std::setw(6) << countOfCurrentVertex << "     |  ";
					for (int i = 0; i < queue.size(); i++)
					{
						std::cout << queue[i] << " ";
					}
					std::cout << std::endl;
				}
			}

		}
		queue.erase(queue.begin());
		{ //output:
			std::cout << "    -   |     -     |  ";
			for (int i = 0; i < queue.size(); i++)
			{
				std::cout << queue[i] << " ";
			}
			if (queue.size() == 0)
				std::cout << "- ";
			std::cout << std::endl;
		}
	}
}

std::vector<int> Graph::getPathBFS(int start, int end)
{
	std::vector<int> result;

	if (!hasPath(start, end))
		return result;

	int startVertex = start;
	int endVertex = end;

	std::vector<int> queue;
	std::vector<bool> used(vertices.size() + 1);
	std::vector<int> parent(vertices.size() + 1);

	queue.push_back(startVertex);
	used[startVertex] = true;
	parent[startVertex] = -1;

	bool condition = false;
	while (!condition)
	{
		int currentVertex = queue.front();

		for (int i = 0; i< adjacencyMatrix[currentVertex - 1].size(); i++)
		{
			if (adjacencyMatrix[currentVertex - 1][i] > 0)
			{
				int someVertex = i + 1;
				if (!used[someVertex])
				{
					used[someVertex] = true;
					queue.push_back(someVertex);
					parent[someVertex] = currentVertex;
				}
				if (someVertex == endVertex)
				{
					condition = true;
					break;
				}
			}

		}
		queue.erase(queue.begin());
		if (queue.empty())
			condition = true;
	}

	int currentVertex = end;
	while(currentVertex > 0)
	{
		result.push_back(currentVertex);
		currentVertex = parent[currentVertex];
	}
	std::vector<int> returnResult(result.size());
	for (int i = 0; i < returnResult.size(); i++)
	{
		returnResult[i] = result[(result.size() - 1) - i];
	}
	return returnResult;
}

//---DFS

void Graph::DFS(int startVertex)
{
	if (!hasVertex(startVertex))
	{ // chech error
		std::cout << " !!! DFS bypassing is not available!" << std::endl;
		return;
	}

	std::vector<int> queue;
	std::vector<bool> used(vertices.size() + 1);
	queue.push_back(startVertex);
	used[startVertex] = true;

	//output:
	int countOfCurrentVertex = 0;
	{
		countOfCurrentVertex++;
		std::cout << " VERTEX | DFS count |  QUEUE    " << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::setw(5) << startVertex << "   |" << std::setw(6) << countOfCurrentVertex << "     |  ";
		for (int i = 0; i < queue.size(); i++)
			std::cout << queue[i] << " ";
		std::cout << std::endl;
	}//::output

	int currentVertex = queue.back();
	while (!queue.empty())
	{
		currentVertex = queue.back();
		bool condition = false;
		for (int i = 0; i < adjacencyMatrix[currentVertex - 1].size(); i++)
		{
			int someVertex = i + 1;
			if (adjacencyMatrix[currentVertex - 1][i] > 0 && !used[someVertex])
			{
				used[someVertex] = true;
				queue.push_back(someVertex);
				condition = true;
				
				{ //output:
					countOfCurrentVertex++;
					std::cout << std::setw(5) << someVertex << "   |" << std::setw(6) << countOfCurrentVertex << "     |  ";
					for (int i = 0; i < queue.size(); i++)
						std::cout << queue[i] << " ";
					std::cout << std::endl;
				}
				break;
			}

		}
		
		if (!condition)
		{
			queue.pop_back(); // delete vertex if havn't new way
			{ //output:
				std::cout << "    -   |     -     |  ";
				for (int i = 0; i < queue.size(); i++)
				{
					std::cout << queue[i] << " ";
				}
				if (queue.size() == 0)
					std::cout << "- ";
				std::cout << std::endl;
			}
		}	
	}
}

//------ END ----------------------- algorithms -------------------------------------


std::ostream& operator<<(std::ostream &strm, const Graph & ag) 
{
	strm << "------- Graph ------" << std::endl;
	strm << "   EDGE    | VERTEX " << std::endl;
	strm << "--------------------" << std::endl;
	int count = 0;
	if (ag.edges.size() > ag.vertices.size())
		count = ag.edges.size();
	else
		count = ag.vertices.size();
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