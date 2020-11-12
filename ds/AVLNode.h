#ifndef AVLNODE_H
#define AVLNODE_H

template <class T>
class AVLNode {
 private:
  int bf;  // balance factor
  T data;
  AVLNode *left;
  AVLNode *right;

 public:
  AVLNode(T);
  int getBF();
  T getData();
  AVLNode<T> *getLeft();
  AVLNode<T> *getRight();
  void setBF(int);
  void setLeft(AVLNode<T> *);
  void setRight(AVLNode<T> *);
};

template <class T>
AVLNode<T>::AVLNode(T data) {
  this->bf = 0;
  this->data = data;
  this->left = NULL;
  this->right = NULL;
}

template <class T>
int AVLNode<T>::getBF() {
  return this->bf;
}

template <class T>
T AVLNode<T>::getData() {
  return this->data;
}

template <class T>
AVLNode<T> *AVLNode<T>::getLeft() {
  return this->left;
}

template <class T>
AVLNode<T> *AVLNode<T>::getRight() {
  return this->right;
}

template <class T>
void AVLNode<T>::setBF(int bf) {
  this->bf = bf;
}

template <class T>
void AVLNode<T>::setLeft(AVLNode<T> *left) {
  this->left = left;
}

template <class T>
void AVLNode<T>::setRight(AVLNode<T> *right) {
  this->right = right;
}

#endif
