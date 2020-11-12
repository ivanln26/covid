#include <iostream>

#include "Caso.h"
#include "ds/AVLNode.h"

#ifndef CMAKE_COVID_ESTADISTICA_H
#define CMAKE_COVID_ESTADISTICA_H

#define RANGO_ETARIO 14

class Estadistica {
 private:
  int n_muestras;
  int n_infectados;
  int n_fallecidos;
  float porcentaje_infectados;
  float porcentaje_fallecidos;
  int *n_infectados_edad;
  int *n_fallecidos_edad;
  void preorder(AVLNode<Caso> *);

 public:
  Estadistica(AVLNode<Caso> *);
  ~Estadistica();
  void toString();
};

#endif  // CMAKE_COVID_ESTADISTICA_H
