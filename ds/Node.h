#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
 private:
  T data;
  Node *next;

 public:
  Node(T);
  T getData();
  Node *getNext();
  void setData(T);
  void setNext(Node *);
};

template <class T>
Node<T>::Node(T data) {
  this->data = data;
  this->next = NULL;
}

template <class T>
T Node<T>::getData() {
  return this->data;
}

template <class T>
Node<T> *Node<T>::getNext() {
  return this->next;
}

template <class T>
void Node<T>::setData(T data) {
  this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T> *next) {
  this->next = next;
}

#endif
