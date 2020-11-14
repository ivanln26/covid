#include "Contador.h"

Contador::Contador(AVLNode<Caso> *root) {
  this->root = root;
}

void Contador::contarPCasos(int n) {
  for (int i = 0; i < N_PROVINCIAS; i++) {
    this->p_casos[i] = 0;
  }

  this->contarPCasos(this->root);

  int total = 0;
  for (int i = 0; i < N_PROVINCIAS; i++) {
    printf("%s: %d\n", this->provincias[i].c_str(), this->p_casos[i]);
    total += this->p_casos[i];
  }
  printf("Total: %d\n", total);
}

void Contador::contarPCasos(AVLNode<Caso> *n) {
  if (n == NULL) return;

  std::string provincia = n->getData().getProvincia();
  for (int i = 0; i < N_PROVINCIAS; i++) {
    if (this->provincias[i].compare(provincia) == 0 &&
        n->getData().getClasificacion()) {
      this->p_casos[i]++;
    }
  }

  this->contarPCasos(n->getLeft());
  this->contarPCasos(n->getRight());
}
