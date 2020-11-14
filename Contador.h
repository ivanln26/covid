#include <stdio.h>

#include "Caso.h"
#include "ds/AVLNode.h"

#ifndef CONTADOR_H
#define CONTADOR_H

#define N_PROVINCIAS 24

class Contador {
 private:
  std::string provincias[N_PROVINCIAS] = {
      "Buenos Aires",
      "CABA",
      "Catamarca",
      "Chaco",
      "Chubut",
      "Córdoba",
      "Corrientes",
      "Entre Ríos",
      "Formosa",
      "Jujuy",
      "La Pampa",
      "La Rioja",
      "Mendoza",
      "Misiones",
      "Neuquén",
      "Río Negro",
      "Salta",
      "San Juan",
      "San Luis",
      "Santa Cruz",
      "Santa Fe",
      "Santiago del Estero",
      "Tierra del Fuego",
      "Tucumán",
  };
  int p_casos[N_PROVINCIAS];
  int p_muertes[N_PROVINCIAS];
  AVLNode<Caso> *root;
  void contarPCasos(AVLNode<Caso> *);
  void contarPMuertes(AVLNode<Caso> *);

 public:
  Contador(AVLNode<Caso> *);
  void contarPCasos(int);
  void contarPMuertes(int);
};

#endif
