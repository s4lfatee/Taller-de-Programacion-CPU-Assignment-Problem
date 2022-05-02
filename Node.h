#include <iostream>
#include <vector>

using namespace std;

// Node class that represents a cell state in the maze
// contains i and j axis coordinates, an heuristic value (in maze context) and a pointer to the previous node

class Node {
public:
    Node(); // Constructor of Node class
    ~Node(); // Destructor of Node class
    Node(Node* node); // Constructor of Node class, copies the values of the input node
    Node(int i, int j, vector<int> assigned, Node* previous); // Constructor of Node class with the given parameters
    Node(int i, int j, vector<int> assigned, int cost, int totalcost, Node* previous); // Constructor of Node class with the given parameters

    int get_i(); // getter for i
    int get_j(); // getter for j
    int get_totalCost(); // getter for totalcost
    Node *getPrevious(); // getter for previous node
    int get_Cost(); // getter for cost
    vector<int> get_assigned(); // getter for assigned vector
    
    void setPrevious(Node *previous);
    void setCost(int value);
    void setTotalCost(int value);
    void set_i(int value);
    
    // main methods
    string getPath(); // Traces back the path by accessing the previous nodes
    void print(); // Prints the i, j and cost value of a node

private:
    // particular variables of this problem
    int i; // row
    int j; // column
    int totalcost;
    int cost; // a value representing a cost for choosing this node
    vector<int> assigned; // a vector of assigned processes, it's represented as a vector of zeros and ones

    // structural variables: meaning relationships between nodes
    Node *previous; // the previous node in the path
};  // end class Node