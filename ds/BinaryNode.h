#ifndef BINARYNODE_H
#define BINARYNODE_H

template <class T>
class BinaryNode {
  private:
    T data;
    BinaryNode *left;
    BinaryNode *right;

  public:
    BinaryNode(T);
    T getData();
    BinaryNode<T> *getLeft();
    BinaryNode<T> *getRight();
    void setLeft(BinaryNode<T> *);
    void setRight(BinaryNode<T> *);
};

template <class T>
BinaryNode<T>::BinaryNode(T data) {
  this->data = data;
  this->left = NULL;
  this->right = NULL;
}

template <class T>
T BinaryNode<T>::getData() {
  return this->data;
}

template <class T>
BinaryNode<T> *BinaryNode<T>::getLeft() {
  return this->left;
}

template <class T>
BinaryNode<T> *BinaryNode<T>::getRight() {
  return this->right;
}

template <class T>
void BinaryNode<T>::setLeft(BinaryNode<T> *left) {
  this->left = left;
}

template <class T>
void BinaryNode<T>::setRight(BinaryNode<T> *right) {
  this->right = right;
}

#endif
