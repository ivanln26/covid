#include <iostream>

#ifndef CMAKE_COVID_ESTADISTICA_H
#define CMAKE_COVID_ESTADISTICA_H

class Estadistica {
 private:
  int n_muestras;
  int n_infectados;
  int n_fallecidos;
  float porcentaje_infectados;
  float porcentaje_fallecidos;
  int *n_infectados_edad;
  int *n_fallecidos_edad;

 public:
  Estadistica();
  Estadistica(int, int, int, int *, int *);
  void calcularPorcentajes();
  void toString();
};

#endif  // CMAKE_COVID_ESTADISTICA_H
