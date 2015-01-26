
/*
#pragma once
#ifndef _MATRICES_H
#define _MATRICES_H_

class Graph;

#include <iomanip>

#include "Graph.h"


class Matrices
{
private:
	Graph * graph;
	int** incedenceMatrix;
	int** adjacencyMatrix;

	int line;
	int column;

public:
	Matrices(Graph * graph);
	~Matrices();

	void outputIncedenceMatrix();
	void outputAdjacencyMatrix();

	void setIncedenceMatrix(int ** matrix);
	void setAdjacencyMatrix(int ** matrix);
	void setVerticesCount(int count);
	void setEdgesCount(int count);


	int ** getAdjacencyMatrix();
	int ** getIncedenceMatrix();
	void update();
};

#endif */