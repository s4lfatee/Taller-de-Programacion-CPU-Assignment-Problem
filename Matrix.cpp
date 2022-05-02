#include "Matrix.h"

/*
 * Constructor of Matrix class
 * @param size - the size of the matrix
*/
Matrix::Matrix(int size){
    Matrix::size = size;
    arr = new int*[size];
    for(int i = 0; i < size; i++){
        arr[i] = new int[size];
        for(int j = 0; j < size; j++){
            arr[i][j] = 0;
        }
    }
}

/*
 * Destructor of Matrix class
*/
Matrix::~Matrix(){
    for(int i = 0; i < size; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

/*
 * Prints the matrix
*/
void Matrix::print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

/* 
 * Checks if the matrix cell is assigned
 * @param i - the row of the cell
 * @param j - the column of the cell
 * @return bool - true if the cell is assigned, false otherwise
*/
bool Matrix::isAssigned(int i, int j){
    if (arr[i][j] == 1){
        return true;
    }
    return false;
}

/*
 * Assigns the matrix cell
 * @param i - the row of the cell
 * @param j - the column of the cell
*/
void Matrix::setAssigned(int i, int j){
    arr[i][j] = 1;
}

/*
 * Sets all matrix cells to zero
*/
void Matrix::clear(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            arr[i][j] = 0;
        }
    }
}