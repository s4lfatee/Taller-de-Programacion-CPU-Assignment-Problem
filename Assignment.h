#include <iostream>
#include "Cost.h"
#include "Container.h"
#include "Matrix.h"
#include <math.h>
#define GREEN "\033[32m"
#define RESET "\033[0m"

// This class represents assignment problem using a cost matrix

class Assignment{
    public:
    Assignment(int N); // Constructor
    ~Assignment(); // Destructor
    int solve(); // Solves the assignment problem using the Branch and Bound algorithm
    void print(); // prints the cost matrix
    void refresh(); // refreshes the cost matrix and restarts the bool matrix

    private:
    Cost *cost; // Cost matrix
    Matrix *boolmatrix; // Matrix of booleans that represents the position of assigned processes
};