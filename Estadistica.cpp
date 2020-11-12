#include "Estadistica.h"

Estadistica::Estadistica(BinaryNode<Caso> *root) {
  this->n_muestras = 0;
  this->n_infectados = 0;
  this->n_fallecidos = 0;
  this->porcentaje_infectados = 0;
  this->porcentaje_fallecidos = 0;
  this->n_infectados_edad = NULL;
  this->n_fallecidos_edad = NULL;
  this->preorder(root);
  this->porcentaje_infectados =
      (float)this->n_infectados / this->n_muestras * 100;
  this->porcentaje_fallecidos =
      (float)this->n_fallecidos / this->n_muestras * 100;
}

void Estadistica::preorder(BinaryNode<Caso> *node) {
  if (node == NULL) return;

  this->n_muestras++;
  if (node->getData().getClasificacion()) this->n_infectados++;
  if (node->getData().getFallecido()) this->n_fallecidos++;

  this->preorder(node->getLeft());
  this->preorder(node->getRight());
};

void Estadistica::toString() {
  std::cout << this->n_muestras << std::endl;
  std::cout << this->n_infectados << std::endl;
  std::cout << this->n_fallecidos << std::endl;
  std::cout << this->porcentaje_infectados << std::endl;
  std::cout << this->porcentaje_fallecidos << std::endl;
  std::cout << this->n_infectados_edad << std::endl;
  std::cout << this->n_fallecidos_edad << std::endl;
}
