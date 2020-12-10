/** CS515 Assignment 4
 * File: stack.cpp
 * Name: Mily Pagan
 * Section: 02
 * Date: 10/06/20
 * Collaboration Declaration: piazza and lab 3*/

#include "stack.h"

// constructor with default capacity value
stack::stack(TYPE size){
    _tos = -1;
    _capacity = size; //8
    _arr = new int[_capacity];
    for (int i=0; i< _capacity; i++) {
        _arr[i] = 0;    // Initialize all elements to zero.
    }
}
// copy constructor
stack::stack(const stack& source){
    _capacity = source._capacity;
    _arr = new int[_capacity];
    _tos = source._tos;
    for (int i = 0; i <= _tos; i++) {
        _arr[i] = source._arr[i];
    }
}
// assignment operator
stack& stack::operator= (const stack& source) {
    if (this == &source) {
        return *this;
    }
    delete []_arr;
    _tos = source._tos;
    _capacity = source._capacity;
    _arr = source._arr;
    if (size() > 0) {
        _arr = new int[_capacity];
        for (int i = 0; i < size(); i++) {
            _arr[i] = source._arr[i];
        }
    }
    return *this;
}

// destructor
stack::~stack() {
    delete [] _arr;
}
// add an element into the stack, if stack is full, expand the capacity of the stack by 2
void stack::push(TYPE num) {
    if (_tos == _capacity - 1) { //if stack is full
        _capacity = _capacity * 2;
        int *_newArray = new int[_capacity];
        for (int i = 0; i <= size(); i++) {
            _newArray[i] = _arr[i];
        }
        delete [] _arr;
        _arr = _newArray;
        _tos++;
        _arr[_tos] = num;
    }  else {
        _tos++;
        _arr[_tos] = num;
    }
}
//remove an element from the stack
void stack::pop() {
    if (size() == 0) {
        throw EmptyStackException();
    } else {
        _tos--;
        _arr[_tos];
    }
}
//return top element in stack
TYPE& stack::top() {
    if (!empty()) {
        return _arr[_tos];
    } else {
        throw EmptyStackException();
    }
}
//return true if stack is empty false otherwise
bool stack::empty() {
    return (size() == 0) ? true : false;
}
//return number of elements in the stack
int stack::size() {
    return _tos + 1;
}
//return current capacity of the stack
int stack::capacity() {
    return _capacity;
}

void stack::dump(ostream &os) {
    for (int i = _capacity - 1; i > 0; i--) {
        os << _arr[i];
        if (i != 0) {
            os << " ";
        }
    }
    os << _arr[0] << endl;
}
