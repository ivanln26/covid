#include "Case.h"

#ifndef CASEARRAY_H
#define CASEARRAY_H

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

CaseArray::CaseArray(int capacity) {
  this->arr = new Case[capacity];
  this->capacity = capacity;
  this->size = 0;
}

void CaseArray::append(Case c) {
  this->arr[size] = c;
  this->size++;
}

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
