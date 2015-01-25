#include <iomanip>


struct Matrix {
	int** matrix;
	int line;
	int column;

	void outputMatrix()
	{
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
			std::cout << " v" << (i+1) << " | ";
			for (int j = 0; j < column; j++)
			{
				std::cout << std::setw(3) << matrix[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};