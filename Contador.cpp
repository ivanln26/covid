#include "Contador.h"

Contador::Contador(AVLNode<Caso> *root) { this->root = root; }

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

void Contador::contarPMuertes(int n) {
  for (int i = 0; i < N_PROVINCIAS; i++) {
    this->p_muertes[i] = 0;
  }

  this->contarPMuertes(this->root);

  int total = 0;
  for (int i = 0; i < N_PROVINCIAS; i++) {
    printf("%s: %d\n", this->provincias[i].c_str(), this->p_muertes[i]);
    total += this->p_muertes[i];
  }
  printf("Total: %d\n", total);
}

void Contador::contarPMuertes(AVLNode<Caso> *n) {
  if (n == NULL) return;

  std::string provincia = n->getData().getProvincia();
  for (int i = 0; i < N_PROVINCIAS; i++) {
    if (this->provincias[i].compare(provincia) == 0 &&
        n->getData().getFallecido()) {
      this->p_muertes[i]++;
    }
  }

  this->contarPMuertes(n->getLeft());
  this->contarPMuertes(n->getRight());
}

void Contador::casoEdad(int ano) {
    this->casoEdad(this->root, ano);
    Node<Caso>*aux = this->casosEdad.gethead();
    while (aux != NULL ){
        aux->getData().toString();
        aux = aux->getNext();
    }
}

void Contador::casoEdad(AVLNode<Caso> *node, int ano) {
    if (node == NULL) return;
    if (node->getData().getEdad() == ano){
        this->casosEdad.prepend(node->getData());
    }
    this->casoEdad(node->getLeft(), ano);
    this->casoEdad(node->getRight(), ano);
}