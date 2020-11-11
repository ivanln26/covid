#include "BinaryNode.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
class BinaryTree {
 private:
  BinaryNode<T> *root;
  BinaryNode<T> *insert(BinaryNode<T> *, T);
  void preorder(BinaryNode<T> *);

 public:
  BinaryTree();
  ~BinaryTree();
  void insert(T);
  bool isEmpty();
  void toString();
};

template <class T>
BinaryTree<T>::BinaryTree() {
  this->root = NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
  this->root = NULL;
}

template <class T>
void BinaryTree<T>::insert(T data) {
  this->root = this->insert(this->root, data);
}

template <class T>
BinaryNode<T> *BinaryTree<T>::insert(BinaryNode<T> *n, T data) {
  if (n == NULL) {
    return new BinaryNode<T>(data);
  }

  if (n->getData() == data) {
    throw 404;
  }

  if (n->getData() > data) {
    BinaryNode<T> *left = insert(n->getLeft(), data);
    n->setLeft(left);
  } else {
    BinaryNode<T> *right = insert(n->getRight(), data);
    n->setRight(right);
  }

  return n;
}

template <class T>
bool BinaryTree<T>::isEmpty() {
  return this->root == NULL;
}

template <class T>
void BinaryTree<T>::preorder(BinaryNode<T> *n) {
  if (n == NULL) {
    return;
  }

  // std::cout << n->getData().toString() << " ";
  n->getData().toString();
  preorder(n->getLeft());
  preorder(n->getRight());
}

template <class T>
void BinaryTree<T>::toString() {
  this->preorder(this->root);
}

#endif
