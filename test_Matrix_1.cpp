#include "Matrix.h"

int main(){
    Matrix c(10);
    // Set both 1,1 and 5,10 to be visited
    c.setAssigned(1,1);
    c.setAssigned(4,9);
    // Print the matrix
    c.print();

    // Print the visited state of 1,1
    if (c.isAssigned(1,1)){
        cout << "Visited" << endl;
    }
    else{
        cout << "Not visited" << endl;
    }

    c.clear();
    c.print();

    return 0;
}