#ifndef COST_H
#define COST_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <climits>
using namespace std;
/*
Represent the cost to run a process j in in a given machine i.
Cost are generated randomly. We assume that generateCost() is 
not called a huge number of times, it has performance issues.
*/
class Cost  {
private:
    int N; // size of the square cost matrix
    int **cost; // cost matrix
    int isNotNewCost(int i, int j); // auxiliary function to check if the cost is new in row i
public:
    Cost(int N); // Receive the size of the problem
    ~Cost(); // Destructor
    void setCost(int i, int j, int value);
    int getCost(int i, int j);
    int getN(); // getter for the size of the matrix
    void generateCost(); // Generate random cost, reentrant function
    void print(); // Print the cost matrix
    int CalculateCost(int i, int j, vector<int> assigned); // Calculate the cost of assigning process i to cpu j
};

#endif