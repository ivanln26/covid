#include "Estadistica.h"

Estadistica::Estadistica(AVLNode<Caso> *root) {
  this->n_muestras = 0;
  this->n_infectados = 0;
  this->n_fallecidos = 0;
  this->porcentaje_infectados = 0;
  this->porcentaje_fallecidos = 0;
  this->n_infectados_edad = new int[RANGO_ETARIO];
  this->n_fallecidos_edad = new int[RANGO_ETARIO];
  for (int i = 0; i < RANGO_ETARIO; i++) {
    this->n_infectados_edad[i] = 0;
    this->n_fallecidos_edad[i] = 0;
  }
  this->preorder(root);
  this->porcentaje_infectados =
      (float)this->n_infectados / this->n_muestras * 100;
  this->porcentaje_fallecidos =
      (float)this->n_fallecidos / this->n_muestras * 100;
}

Estadistica::~Estadistica() {
  delete[] this->n_infectados_edad;
  delete[] this->n_fallecidos_edad;
  this->n_infectados_edad = NULL;
  this->n_fallecidos_edad = NULL;
}

void Estadistica::preorder(AVLNode<Caso> *node) {
  if (node == NULL) return;

  int rango_etario = node->getData().getEdad() / 10;
  this->n_muestras++;
  if (node->getData().getClasificacion()) {
    this->n_infectados++;
    this->n_infectados_edad[rango_etario]++;
  }
  if (node->getData().getFallecido()) {
    this->n_fallecidos++;
    this->n_fallecidos_edad[rango_etario]++;
  }

  this->preorder(node->getLeft());
  this->preorder(node->getRight());
};

void Estadistica::toString() {
  std::cout << this->n_muestras << std::endl;
  std::cout << this->n_infectados << std::endl;
  std::cout << this->n_fallecidos << std::endl;
  std::cout << this->porcentaje_infectados << std::endl;
  std::cout << this->porcentaje_fallecidos << std::endl;

  std::cout << "[ ";
  for (int i = 0; i < RANGO_ETARIO; i++) {
    std::cout << this->n_infectados_edad[i] << " ";
  }
  std::cout << "]" << std::endl;

  std::cout << "[ ";
  int counter = 0;
  for (int i = 0; i < RANGO_ETARIO; i++) {
    std::cout << this->n_fallecidos_edad[i] << " ";
  }
  std::cout << "]" << std::endl;
}
