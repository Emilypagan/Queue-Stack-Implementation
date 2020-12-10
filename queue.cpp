/** CS515 Assignment 4
 * File: queue.cpp
 * Name: Mily Pagan
 * Section: 02
 * Date: 10/06/20
 * Collaboration Declaration: piazza and lab 3*/

//provides an implementation of the class using a fixed sized array
#include "queue.h"

// constructor with default capacity value
queue::queue(TYPE sz){
    _capacity = sz;
    _arr = new int[_capacity];
    _size = 0;
    _front = -1;  // front points to queue front
    for(int i=0; i < _capacity; i++)
        _arr[i]=0;
}
// copy constructor
queue::queue(const queue& source) {
    _capacity = source._capacity;
    _size = source._size;
    _arr = new int[_capacity];
    _front = source._front;
    for (int i = _front - _size + 1; i <= _front; i++) {
        _arr[i] = source._arr[i];
    }
}
// assignment operator
queue& queue::operator=(const queue& source) {
    if (this == &source) {
        return *this;
    }
    //delete _arr;
    _front = source._front;
    _capacity = source._capacity;
    _size = source._size;
    _arr = source._arr;
    if (source._size > 0) {
        _arr = new int[_capacity];
        for (int i = 0; i < _size; i++) {
            _arr[i] = source._arr[i];
        }
    }
    return *this;
}
//destructor
queue::~queue() {
    delete [] _arr;
}
//add an element into the queue
void queue::enqueue(int data){
    if (_size == _capacity) {
        _capacity = _capacity * 2;
        int *newArray = new int[_capacity];
        for (int i = _front - _size + 1; i <= _front; i++) {
            newArray[i] = _arr[i];
        }
        delete[] _arr;
        _arr = newArray;
        _size++;
        _front++;
        _arr[_front] = data;
    } else {
        _front++;
        _front = _front % _capacity;
        _arr[_front] = data;
        _size++;
    }
}
//remove the first element
TYPE queue::dequeue(){
    if (!empty()) {
        int out = _arr[_front - _size + 1];
        _size--;
        return out;
    } else {
        throw EmptyQueueException();
    }
}
// access the element at queue front; does not remove the element
TYPE& queue::front(){
    if (empty()) {
        throw EmptyQueueException();
    } else {
        return _arr[_front - _size + 1];
    }
}
// return true if the queue is empty, false otherwise
bool queue::empty(){
    return (_size == 0) ? true : false;
}
// return the number of elements currently in the queue
int queue::size(){
    return _size;
}
// return the current capacity of the queue
int queue::capacity(){
    return _capacity;
}
// output queue elements from queue front to queue end
// elements are separated with a white space.
void queue::dump(ostream &os){
    int n = _front;
    for (int i = 0; i < _size; i++) {
        n = n - 1;
        if (n == -1) {
            n = _capacity;
        }
    }
    for (int i = 0; i < _size; i++) {
        os << _arr[n];
        n++;
        n = n % _capacity;
        if (i != _size - 1) {
            os << " ";
        }
    }
    os << endl;
}
