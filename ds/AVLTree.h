#include "AVLNode.h"

#ifndef AVLTREE_H
#define AVLTREE_H

template <class T>
class AVLTree {
 private:
  AVLNode<T> *root;
  AVLNode<T> *insert(AVLNode<T> *, T, bool &);
  AVLNode<T> *rotationLL(AVLNode<T> *, AVLNode<T> *);
  AVLNode<T> *rotationLR(AVLNode<T> *, AVLNode<T> *);
  AVLNode<T> *rotationRR(AVLNode<T> *, AVLNode<T> *);
  AVLNode<T> *rotationRL(AVLNode<T> *, AVLNode<T> *);
  void preorder(AVLNode<T> *);

 public:
  AVLTree();
  ~AVLTree();
  void insert(T);
  AVLNode<T> *getRoot();
  bool isEmpty();
  void toString();
};

template <class T>
AVLTree<T>::AVLTree() {
  this->root = NULL;
}

template <class T>
AVLTree<T>::~AVLTree() {
  this->root = NULL;
}

template <class T>
AVLNode<T> *AVLTree<T>::rotationLL(AVLNode<T> *a, AVLNode<T> *b) {
  a->setLeft(b->getRight());
  b->setRight(a);
  if (b->getBF() == -1) {
    a->setBF(0);
    b->setBF(0);
  } else {
    a->setBF(-1);
    b->setBF(1);
  }
  return b;
}

template <class T>
AVLNode<T> *AVLTree<T>::rotationLR(AVLNode<T> *a, AVLNode<T> *b) {
  AVLNode<T> *c;
  c = b->getRight();
  a->setLeft(c->getRight());
  c->setRight(a);
  b->setRight(c->getLeft());
  c->setLeft(b);
  if (c->getBF() == 1)
    b->setBF(-1);
  else
    b->setBF(0);
  if (c->getBF() == -1)
    a->setBF(1);
  else
    a->setBF(0);
  c->setBF(0);
  return c;
}

template <class T>
AVLNode<T> *AVLTree<T>::rotationRR(AVLNode<T> *a, AVLNode<T> *b) {
  a->setRight(b->getLeft());
  b->setLeft(a);
  if (b->getBF() == 1) {
    a->setBF(0);
    b->setBF(0);
  } else {
    a->setBF(1);
    b->setBF(-1);
  }
  return b;
}

template <class T>
AVLNode<T> *AVLTree<T>::rotationRL(AVLNode<T> *a, AVLNode<T> *b) {
  AVLNode<T> *c;
  c = b->getLeft();
  a->setRight(c->getLeft());
  c->setLeft(a);
  b->setLeft(c->getRight());
  c->setRight(b);
  if (c->getBF() == 1)
    a->setBF(-1);
  else
    a->setBF(0);
  if (c->getBF() == -1)
    b->setBF(1);
  else
    b->setBF(0);
  c->setBF(0);
  return c;
}

template <class T>
void AVLTree<T>::insert(T data) {
  bool hc = false;
  this->root = this->insert(this->root, data, hc);
}

template <class T>
AVLNode<T> *AVLTree<T>::insert(AVLNode<T> *n, T data, bool &hc) {
  if (n == NULL) {
    hc = true;
    return new AVLNode<T>(data);
  }

  if (data == n->getData()) throw 404;

  if (data < n->getData()) {
    AVLNode<T> *left = insert(n->getLeft(), data, hc);
    n->setLeft(left);
    if (hc) {
      switch (n->getBF()) {
        case 1:
          n->setBF(0);
          hc = false;
          break;
        case 0:
          n->setBF(-1);
          break;
        case -1:
          AVLNode<T> *aux = n->getLeft();
          if (aux->getBF() == -1)
            n = rotationLL(n, aux);
          else
            n = rotationLR(n, aux);
          hc = false;
      }
    }
  } else if (data > n->getData()) {
    AVLNode<T> *right = insert(n->getRight(), data, hc);
    n->setRight(right);
    if (hc) {
      switch (n->getBF()) {
        case 1: {
          AVLNode<T> *aux = n->getRight();
          if (aux->getBF() == 1)
            n = rotationRR(n, aux);
          else
            n = rotationRL(n, aux);
          hc = false;
          break;
        }
        case 0: {
          n->setBF(1);
          break;
        }
        case -1: {
          n->setBF(0);
          hc = false;
          break;
        }
      }
    }
  }
  return n;
}

template <class T>
AVLNode<T> *AVLTree<T>::getRoot() {
  return this->root;
}

template <class T>
bool AVLTree<T>::isEmpty() {
  return this->root == NULL;
}

template <class T>
void AVLTree<T>::preorder(AVLNode<T> *n) {
  if (n == NULL) {
    return;
  }

  // std::cout << n->getData().toString() << " ";
  n->getData().toString();
  preorder(n->getLeft());
  preorder(n->getRight());
}

template <class T>
void AVLTree<T>::toString() {
  this->preorder(this->root);
}

#endif
