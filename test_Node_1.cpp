#include "Node.h"

int main(){
    vector<int> assigned(10, 0);
    Node *node = new Node(1, 2, assigned, NULL);
    node->print();

    Node *othernode = new Node(1, 5, node->get_assigned(), 10, 20, node);

    Node *thirdnode = new Node(node);
    thirdnode->set_i(9);

    othernode->set_i(10);
    othernode->setCost(11);
    othernode->setTotalCost(30);
    othernode->setPrevious(thirdnode);

    cout << "The cost value of the node is: " << othernode->get_Cost() << endl;
    cout << "The previous node of the node is: ";
    othernode->getPrevious()->print();

    cout << endl << "The assigned vector of the node is: ";
    for (int i = 0; i < othernode->get_assigned().size(); i++) {
        cout << othernode->get_assigned()[i] << " ";
    }

    cout << endl << "The i and j values of the node are: " << othernode->get_i() << " " << othernode->get_j() << endl;
    cout << "The total cost of the node is: " << othernode->get_totalCost() << endl;
    cout << "The path of the node is: " << othernode->getPath() << endl;

    delete node;
    delete othernode;
    delete thirdnode;
}