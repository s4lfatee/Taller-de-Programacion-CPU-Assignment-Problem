#include "Assignment.h"

int main(){
    Assignment *assignment = new Assignment(5);
    int solution = assignment->solve();
    cout << "Total cost of the assignment: " << solution << endl;
    assignment->print();
    assignment->refresh();
    cout << endl << "Refreshed matrix: " << endl;
    assignment->print();
    assignment->~Assignment();
    return 0;
}