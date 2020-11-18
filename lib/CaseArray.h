#include "Case.h"

#ifndef CASEARRAY_H
#define CASEARRAY_H

// CaseArray represents an array of Cases with a fixed capacity
class CaseArray {
 private:
  Case *arr;
  int capacity;
  int size;

 public:
  CaseArray(int);
  void append(Case);
  void swap(int, int);
  Case operator[](int i);
  int getSize();
  void toString();
};

// Case array constructor creates a new array with 0 size and n capacity
CaseArray::CaseArray(int capacity) {
  this->arr = new Case[capacity];
  this->capacity = capacity;
  this->size = 0;
}

// append inserts a Case element in size position
void CaseArray::append(Case c) {
  this->arr[size] = c;
  this->size++;
}

// swap swaps two elements from the array
void CaseArray::swap(int i, int j) {
  Case aux = this->arr[i];
  this->arr[i] = this->arr[j];
  this->arr[j] = aux;
}

Case CaseArray::operator[](int i) { return arr[i]; };

int CaseArray::getSize() { return this->size; }

void CaseArray::toString() {
  for (int i = 0; i < this->size; i++) {
    this->arr[i].toString();
  }
}

#endif
