#include <iostream>
using namespace std;

// Matrix class that represents a matrix of zeros and ones
// Is used to set or check assigned spots of the matrix
// We use it to get the position of the assigned processes

class Matrix{
public:
	Matrix(int size); // Constructor
	~Matrix(); // Destructor
	void print(); // Print method for testing purposes
	bool isAssigned(int i, int j); // Checks if a cell of the matrix is assigned
	void setAssigned(int i, int j); // Sets a cell of the matrix as assigned
	void clear(); // Sets every cell of the matrix to zero
private:
	int size; // Size of the matrix
	int **arr; // The matrix of zeros and ones
};
