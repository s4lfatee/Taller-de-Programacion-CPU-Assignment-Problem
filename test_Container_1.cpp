#include "Container.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int n=20;
    srand(time(NULL));
    Container h(n);
    vector<int> vectortest(n, 0);

    // inserting random numbers
    for(int i = 0; i < n; i++) {
        int val=rand()%n;
        Node *node = new Node(i, i, vectortest, NULL);
        cout<<"inserting "<<val<<endl;
        h.insert(node);
        delete node;
    }

    // printing heap
    cout << endl << "The Heap" <<endl;
    h.print();

    // wiping the heap so we can test isEmpty method

    h.wipe();

    // testing isEmpty method
    if (h.isEmpty()) {
        cout << "The heap is empty!!" <<endl;
    }
    
    // testing pull
    cout << "Pulling the node with the lowest value" <<endl;
    Node *node = h.pull();

    cout << h.getSize() << endl;

    cout << "If the heap is empty the value must be -1: " << endl;
    cout << h.peek() << endl;
 }