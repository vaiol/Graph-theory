#pragma once
#include "Edge.h"
#include <vector>
#include <queue>

class Graph 
{
private:
	//---graphs
	bool hasVertex(int id);
	int firstVertex();
	virtual bool hasEdge(Edge * edge) = 0;
	//---matrices
	std::vector<std::vector<int>> incedenceMatrix;
	std::vector<std::vector<int>> adjacencyMatrix;
	std::vector<std::vector<int>> distanceMatrix;
	std::vector<std::vector<int>> reachabilityMatrix;
	virtual std::vector<std::vector<int>> createIncedenceMatrix() = 0;
	virtual std::vector<std::vector<int>> createAdjacencyMatrix() = 0;
	std::vector<std::vector<int>> createDistanceMatrix();
	std::vector<std::vector<int>> createReachabilityMatrix();
	std::vector<std::vector<int>> degreeMatrix(std::vector<std::vector<int>> matrix, int degree);
	std::vector<std::vector<int>> transposeMatrix(std::vector<std::vector<int>> matrix);
	std::vector<std::vector<int>> concatenationMatrices(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2);
	void outputSquareMatrix(std::vector<std::vector<int>> matrix, int line);
protected:
	std::vector<Edge> edges;
	std::vector<Vertex> vertices;
public:
	//---graphs
	Graph();
	Graph(Graph * graph);
	~Graph();
	Edge * getEdge(int id);
	Vertex * getVertex(int id);
	bool addEdge(Edge * edge);
	bool addEdge(int vertex1, int vertex2, int weight);
	bool addEdge(int vertex1, int vertex2);
	void addVertex();
	void addVertex(int count);
	void removeEdge(Edge * edge);
	void removeVertex(int id);
	void removeVertex(Vertex * vertex);
	//---matrices
	void outputIncedenceMatrix();
	void outputAdjacencyMatrix();
	void outputDistanceMatrix();
	void outputReachabilityMatrix();
	std::vector<std::vector<int>> getAdjacencyMatrix();
	std::vector<std::vector<int>> getIncedenceMatrix();
	std::vector<std::vector<int>> getDistanceMatrix();
	std::vector<std::vector<int>> getReachabilityMatrix();
	void update();
	//---properties
	int isHomogeneousGraph();
	bool hasCycle();
	//BEGIN-connectivity
	bool isStronglyConnectedGraph();
	bool isWeaklyConnectedGraph();
	bool isUnilaterallyConnectedGraph();
	bool isDisconnectedGraph();
	void outputConnectivity();
	//END-connectivity
	std::vector<std::vector<int>> getDegreeOfVertices();
	std::vector<Vertex> getIsolatedVertices();
	std::vector<Vertex> getHangingVertices();
	void outputDegreeOfVertices();
	void outputIsolatedAndHangingVertices();
	//---algorithms
	//common
	void outputPath(int start, int end);
	bool hasPath(int start, int end);
	int getLengthPath(int start, int end);
	//BFS
	void BFS(int startVertex);
	std::vector<int> getPathBFS(int start, int end);
	//DFS
	void DFS(int startVertex);
	//---operators
	friend std::ostream& operator<<(std::ostream&, const Graph&);
};