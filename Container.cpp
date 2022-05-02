#include "Container.h"

/*
 * Constructor of Container class
 *
 * @param size - the size of the container
 */
Container::Container(int size) {
    Container::size = size;
    count = 0;
    arr = new Node[size];
}

/*
 * Destructor
*/
Container::~Container() {
    delete[] arr;
}

/*
 * Returns the size of the container
 * @return int - the size of the container
*/
int Container::getSize() {
    return size;
}

/*
 * Inserts a node into the container
 * @param node - the node to be inserted
*/
void Container::insert(Node *node) {
    if (count == size) {
        cout << "Container is full" << endl;
        return;
    }
    
    arr[count] = *node; // Notice: copy the node
    arr[count].setCost(node->get_Cost());
    count++;
    bubbleUp ();
}

/*
 * Checks if the container is empty
 * @return int - 0 for if statement purposes
*/
int Container::isEmpty() {
    return count == 0;
}

/*
 * Returns the value of the node with the lowest value (Min-heap property)
 * @return int - the value of the node with the lowest value
*/
int Container::peek() {
    if (isEmpty()) {
        cout << "Container is empty" << endl;
        return(-1);
    }
    return arr[0].get_Cost();
}

/*
 * Prints all the values of the nodes inside of the container
*/
void Container::print() {
/* 
    a: index of the level in the Container. Root is at level 0.
    b: index of the column in the level. Root is at column 0.
    k: index of the node in the Container.
    (1<<a) = 2^a. Each row has 2^a nodes.
    (1<<a)-1 + b is the index of the node in the Container.
    k = (1<<a)-1 + b
    The height of the Container is log2(count)=log(count)/log(2).
*/
    int h = (int)(log(count)/log(2));
    
    for(int a=0;a <= h;a++){
        for(int b=0;b<(1<<a) && ((1<<a)-1+b)<count;b++){
            int k=(1<<a)-1+b;
            cout<<arr[k].get_Cost()<<" ";
        }
        cout << endl;
    }
}

/*
 * Pulls the node with the lowest value (Min-heap property) and returns it
 * @return Node* - the node with the lowest value
*/
Node* Container::pull() {
    if (isEmpty()) {
        cout << "Container is empty" << endl;
        return NULL;
    }
    Node *node = new Node(arr[0]);
    arr[0] = arr[count - 1];
    count--;
    bubbleDown();
    return node;
}

/*
 * Swaps two nodes in the container
 * @param i - the index of the first node
 * @param j - the index of the second node
*/
void Container::swap(int i, int j) {
    Node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
 * Bubbles up the container (Bubble sort)
*/
void Container::bubbleUp(){
    int index = count - 1;
    int parentIndex =  (index - 1) / 2;
    while (index > 0 &&
        parentIndex >= 0 && 
        arr[index].get_Cost() < arr[parentIndex].get_Cost()) {
        swap(index, parentIndex);
        index = parentIndex;
        parentIndex =  (index - 1) / 2;
    }
}

/*
 * Bubbles down the container (Bubble sort)
*/
void Container::bubbleDown(){
    int index = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex < count) {
        // Find the largest child for swapping
        if (arr[leftChildIndex].get_Cost() < arr[index].get_Cost() || 
            arr[rightChildIndex].get_Cost() < arr[index].get_Cost()) {
            if (arr[leftChildIndex].get_Cost() < arr[rightChildIndex].get_Cost()) {
                swap(index, leftChildIndex);
                index = leftChildIndex; // Move to the left child
            } else {
                swap(index, rightChildIndex);
                index = rightChildIndex; // Move to the right child
            }
            // Update the child index
            leftChildIndex = index * 2 + 1;
            rightChildIndex = index * 2 + 2;        
        } else {
            break; // no need to bubble down
        }
    }
}

/*
 * Clears out the contents of the container
*/
void Container::wipe() {
    count = 0;
}