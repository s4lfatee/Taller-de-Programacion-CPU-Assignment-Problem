#include "Assignment.h"
#include <ctime>

// main function of the whole assignment, it will measure the average time to solve 100 different instances of the assignment

int main() {
    unsigned t0, t1;
    int size;
    double time;
    cout << "Please enter the size of the cost matrix to solve: ";
    cin >> size;
    Assignment *a = new Assignment(size);
    double acum = 0; // acumulated time in double type for time accuracy
    for (int i = 0; i < 30; i++){
        t0 = clock();
        a->solve();
        t1 = clock();
        time = (double(t1 - t0) / CLOCKS_PER_SEC);
        cout << "["<<i+1<<"]" <<"Solved in: " << time << "[s] - "<< endl;
        acum += time;
        a->refresh(); // create another maze to solve for the next iteration
    }
    cout << "Average time to solve: " << acum/30 << "[s]" << endl;
    a->~Assignment();
    return 0;
}
