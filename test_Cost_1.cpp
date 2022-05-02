#include "Cost.h"

int main() {
    Cost c(10);
    cout << "Cost matrix:" << endl;
    c.print();
    c.generateCost();
    cout << "New cost matrix:" << endl;
    c.print();

    cout << "The size of the cost matrix is: " << c.getN() << endl;

    c.setCost(0, 0, 1);
    cout << "The cost of 0,0 is: " << c.getCost(0, 0) << endl;

    // Vector for cost calculation testing
    vector<int> assigned(10, 0);
    int cost_value = c.CalculateCost(2, 3, assigned);
    cout << "Calculated cost is: " << cost_value << endl;
    return 0;
}