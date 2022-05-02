#include "Cost.h"

/*
 * Constructor of Cost class
 *
 * @param N - the size of the square matrix
*/
Cost::Cost(int N) {
    this->N = N;
    srand(time(NULL));
    cost=nullptr;
    generateCost();
}

/*
 * Destructor of Cost class
*/
Cost::~Cost() {
    for (int i = 0; i < N; i++) {
        delete[] cost[i];
    }
    delete[] cost;
}

/*
 * Changes the cost of a certain cell
 * @param i - the row of the cell
 * @param j - the column of the cell
*/
void Cost::setCost(int i, int j, int value) {
    cost[i][j] = value;
}

/*
 * Returns the cost of a certain cell
 * @param i - the row of the cell
 * @param j - the column of the cell
*/
int Cost::getCost(int i, int j) {
    return this->cost[i][j];
}

/*
 * Returns the size of the matrix
 * @return int - the size of the matrix
*/
int Cost::getN() {
    return N;
}

/*
 * Generates a random cost matrix with values between 1 and N
 * with no repetition by row.
*/
void Cost::generateCost() {
    // this allows this method to be reentrant
    if (cost != nullptr) {
        delete[] cost;
    }
    cost = new int*[N];
    for (int i = 0; i < N; i++) {
        cost[i] = new int[N];
    }
    // generating a random cost matrix with 1/5 of possible repetition by column
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = 1+rand() % (N+N/5+1);
            while (isNotNewCost(i, j)) {
                cost[i][j] = 1+rand() % (N+N/5+1);
            }
        }
    }

    // overrriding 1/5 of the matrix by the number N/5 without repetition by row
    int k = 0;
    while(k<N/5) {
        int i = rand() % N;
        int j = rand() % N;
        int backup=cost[i][j];
        cost[i][j]=N/5;
        if (!isNotNewCost(i, j)) {
            //cout << i << " " << j << endl;
            k++;
        } else {
            cost[i][j]=backup;
        }
    }
}

/*
 * Prints the cost matrix
*/
void Cost::print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

/*
* Check if the cost is already in the matrix row from the left of j
* @param i - the row of the cell
* @param j - the column of the cell
*/
int Cost::isNotNewCost(int i, int j) {
    for (int k = 0; k < j; k++) {
        if (cost[i][j] == cost[i][k]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Calculates the cost of the assignment
 * @param i - the row of the cell
 * @param j - the column of the cell
 * @param assigned - the vector of assigned processes
 * @return int - the cost of the assignment
*/
int Cost::CalculateCost(int i, int j, vector<int> assigned){
    int cost_c = 0;
    for (int k = i + 1; k < N; k++){
        int min = INT_MAX; // A very clunky way to find minimums
        for (int t = 0; t < N; t++){
            if (!(assigned[t]) && cost[k][t] < min){
                min = cost[k][t];
                }
            }
        cost_c += min;
        }
    return cost_c;
}

