#pragma once 
#include <iostream>

class Vertex
{
private:
	int id;
public:
	Vertex(int id);
	~Vertex();
	int getId();
	void setId(int id);
	friend bool operator==(const Vertex& left, const Vertex& right);
	friend std::ostream& operator<<(std::ostream&, const Vertex&);
};
