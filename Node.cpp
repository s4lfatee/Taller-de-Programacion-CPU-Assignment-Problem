#include "Node.h"

/*
 * Constructor of Node class
*/
Node::Node() {
    this->i = 0;
    this->j = 0;
    this->cost = 0;
    this->previous = NULL;
}

/*
 * Constructor of Node class
 * @param node: Node to be copied
*/
Node::Node(Node* node) {
    this->i = node->i;
    this->j = node->j;
    this->cost = node->cost;
    this->previous = node->previous;
}

/*
 * Constructor of Node class
 * @param i: row index
 * @param j: column index
 * @param assigned: vector of assigned procceses
 * @param parent: parent node
*/
Node::Node(int i, int j, vector<int> assigned, Node* parent) {
    this->i = i;
    this->j = j;
    this->cost = 0;
    this->totalcost = 0;
    this->previous = parent;
    this->assigned = assigned;
    if (j != -1){
        this->assigned[j] = 1;
    }
}

/*
 * Constructor of Node class
 * @param i: row index
 * @param j: column index
 * @param assigned: vector of assigned procceses
 * @param cost: cost of the node
 * @param totalcost: total cost of the node path
 * @param parent: parent node
*/
Node::Node(int i, int j, vector<int> assigned, int cost, int totalcost, Node* parent) {
    this->i = i;
    this->j = j;
    this->cost = cost;
    this->totalcost = totalcost;
    this->previous = parent;
    this->assigned = assigned;
}

/*
 * Destructor of Node class
*/
Node::~Node () {
}

/*
 * Getter of row value
 * @return int - row value
*/
int Node::get_i() {
    return this->i;
}

/*
 * Getter of column value
 * @return int - column value
*/
int Node::get_j() {
    return this->j;
}

/*
 * Getter of previous node
 * @return Node* - previous node
*/
Node* Node::getPrevious() {
    return this->previous;
}

/*
 * Getter of the cost value of a node
 * @return int - cost value
*/
int Node::get_Cost() {
    return this->cost;
}

/*
 * Getter of the total cost value of a node
 * @return int - total cost value
*/
int Node::get_totalCost() {
    return this->totalcost;
}

/*
 * Getter of the assigned vector
 * @return vector<int> - assigned vector
*/
vector<int> Node::get_assigned() {
    return this->assigned;
}

/*
 * Sets the previous node of a node
 * @param node: previous node
*/
void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

/*
 * Prints the i, j and cost value of a node
*/
void Node::print() {
    cout << "(" << this->i << "," << this->j << ")[" << this->cost << "]" << endl;
}



/*
 * the path from the root to the current node as a string
 * @return string - the path
*/
string Node::getPath() {
    string s="("+to_string(this->i)+","+to_string(this->j)+")";
    if (this->previous != NULL) {
        s=s+this->previous->getPath();
    }
    return(s); 
}

/*
 * Sets the cost value of a node
 * @param value: cost value
*/
void Node::setCost(int value) {
    this->cost = value;
}

/*
 * Sets the total cost value of a node
 * @param value: total cost value
*/
void Node::setTotalCost(int value) {
    this->totalcost = value;
}

/*
 * Sets the i value of a node
 * @param value: i value
*/
void Node::set_i(int value) {
    this->i = value;
}