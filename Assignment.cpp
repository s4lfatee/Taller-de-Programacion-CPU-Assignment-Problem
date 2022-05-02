#include "Assignment.h"

/*
 * Constructor of assignment class
 * @param N: number of processes and CPUs
*/
Assignment::Assignment(int N){
    this->cost = new Cost(N);
    this->boolmatrix = new Matrix(N);
}

/*
 * Destructor of assignment class
*/
Assignment::~Assignment(){
    cost->~Cost();
    boolmatrix->~Matrix();
}

/*
 * Prints the cost matrix, if the problem is solved, assigned processes will be displayed on green
*/
void Assignment::print(){
    for (int i = 0; i < this->cost->getN(); i++){
        for (int j = 0; j < this->cost->getN(); j++){
            if (this->boolmatrix->isAssigned(i, j)){
                // If the cell is assigned, print it in green
                cout << GREEN << this->cost->getCost(i, j) << " " << RESET;
            } else {
                // Otherwise, just print the cell
                cout << this->cost->getCost(i, j) << " ";
            }
        }
        cout << endl;
    }
}

/*
    * Solves the assignment problem using the Branch and Bound algorithm
    * @return int - Cost of the solution
*/
int Assignment::solve(){
    Container *heap = new Container(this->cost->getN()*this->cost->getN()); // Min heap
    Container *heap2 = new Container(this->cost->getN()+1); // Another min heap
    vector<int> assigned(cost->getN(), 0);
    // We start from -1,-1 because this way we can look to the next row or column
    Node *start = new Node(-1, -1, assigned, nullptr);
    heap->insert(start);    

    while(!heap->isEmpty()){
        // Get the node with the lowest cost in the heap
        Node *current = heap->pull();

        // We are always one step ahead because we are looking for the next cpu for calculations
        int next_cpu = current->get_i()+1;

        // Get the cost for every node in breadth, so we can discard those whose value are not the minimum (Branch and Bound)
        for (int i = 0; i < this->cost->getN(); i++){
            if (!(current->get_assigned()[i])){
                // Keep in mind that this node constructor sets the assigment of the current node to 1
                Node *nodecheck = new Node(next_cpu, i, current->get_assigned(), current);

                // Cost calculations
                nodecheck->setTotalCost(current->get_totalCost() + this->cost->getCost(next_cpu, i));
                nodecheck->setCost(nodecheck->get_totalCost() + this->cost->CalculateCost(next_cpu, i, current->get_assigned()));
                heap2->insert(nodecheck);
                delete nodecheck;
            }
        }

        // Guard clause to avoid segmantation fault
        // We make sure to stop if the next cpu is the last one, because this only means that we have finished the assignment
        if (next_cpu == this->cost->getN()){
            int min_cost = current->get_totalCost();

            // We set the path in the boolean matrix of the class, so we can display the result with green color (see print() method)
            while ((current->getPrevious() != NULL)){
                if ((current->get_i() != -1) && (current->get_j() != -1)){
                    boolmatrix->setAssigned(current->get_i(), current->get_j());
                    current = current->getPrevious();
                }
            }
            // We delete all of our structures because they are no longer needed
            heap->~Container();
            heap2->~Container();
            delete start;
            delete current;
            return min_cost;
        }

        // Once we get the minimum node in heap2, we add it to our main heap
        current = heap2->pull();
        heap->insert(current);

        delete current;

        // We reset the contents of heap2 because those belong to the previous cpu
        // And they will also provoke memory problems
        heap2->wipe();
    }
    delete start;
    heap->~Container();
    heap2->~Container();
    return 0;
}

/*
 * Generates another cost matrix
 * and restarts the bool matrix
*/
void Assignment::refresh(){
    this->cost->generateCost();
    this->boolmatrix->clear();
}