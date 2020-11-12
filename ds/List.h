#include <iostream>

#include "Node.h"

#ifndef LIST_H
#define LIST_H

template <class T>
class List {
 private:
  Node<T> *head;
  int size;

 public:
  List();
  List(const List<T> &);
  ~List();
  void append(T);
  void clear();
  void prepend(T);
  T getData(int);
  int getSize();
  bool isEmpty();
  T operator[](int);
  void toString();
};

template <class T>
List<T>::List() {
  this->head = NULL;
  this->size = 0;
}

template <class T>
List<T>::List(const List<T> &l) {
  this->head = l.head;
  this->size = l.size;
}

template <class T>
List<T>::~List() {
  this->clear();
}

template <class T>
void List<T>::append(T data) {
  Node<T> *n = new Node<T>(data);

  if (this->isEmpty()) {
    this->head = n;
    this->size++;
    return;
  }

  Node<T> *aux = this->head;
  while (aux->getNext() != NULL) {
    aux = aux->getNext();
  }
  aux->setNext(n);
  this->size++;
}

template <class T>
void List<T>::clear() {
  Node<T> *aux = this->head, *toDelete;
  while (aux != NULL) {
    toDelete = aux;
    aux = aux->getNext();
    delete toDelete;
  }
  this->head = NULL;
  this->size = 0;
}

template <class T>
void List<T>::prepend(T data) {
  Node<T> *n = new Node<T>(data);
  n->setNext(this->head);
  this->head = n;
  this->size++;
}

template <class T>
T List<T>::getData(int pos) {
  if (pos < 0 || pos > this->size) throw 404;

  Node<T> *aux = this->head;
  for (int i = 0; i < pos; i++) {
    aux = aux->getNext();
  }
  return aux->getData();
}

template <class T>
int List<T>::getSize() {
  return this->size;
}

template <class T>
bool List<T>::isEmpty() {
  return this->head == NULL;
}

template <class T>
T List<T>::operator[](int pos) {
  if (pos < 0 || pos > this->size) throw 404;

  Node<T> *aux = this->head;
  for (int i = 0; i < pos; i++) {
    aux = aux->getNext();
  }
  return aux->getData();
}

template <class T>
void List<T>::toString() {
  Node<T> *aux = this->head;
  while (aux != NULL) {
    std::cout << aux->getData() << "->";
    aux = aux->getNext();
  }
  std::cout << "NULL" << std::endl;
}

#endif
