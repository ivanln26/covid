#include "Estadistica.h"

Estadistica::Estadistica() {
  this->n_muestras = 0;
  this->n_infectados = 0;
  this->n_fallecidos = 0;
  this->porcentaje_infectados = 0;
  this->porcentaje_fallecidos = 0;
  this->n_infectados_edad = NULL;
  this->n_fallecidos_edad = NULL;
}

Estadistica::Estadistica(int n_muestras, int n_infectados, int n_fallecidos,
                         int *n_infectados_edad, int *n_fallecidos_edad) {
  this->n_muestras = n_muestras;
  this->n_infectados = n_infectados;
  this->n_fallecidos = n_fallecidos;
  this->porcentaje_infectados = 0;
  this->porcentaje_fallecidos = 0;
  this->n_infectados_edad = NULL;
  this->n_fallecidos_edad = NULL;
}

void Estadistica::calcularPorcentajes() {
  this->porcentaje_infectados =
      (float)this->n_infectados / this->n_muestras * 100;
  this->porcentaje_fallecidos =
      (float)this->n_fallecidos / this->n_muestras * 100;
}

void Estadistica::toString() {
  std::cout << this->n_muestras << std::endl;
  std::cout << this->n_infectados << std::endl;
  std::cout << this->n_fallecidos << std::endl;
  std::cout << this->porcentaje_infectados << std::endl;
  std::cout << this->porcentaje_fallecidos << std::endl;
  std::cout << this->n_infectados_edad << std::endl;
  std::cout << this->n_fallecidos_edad << std::endl;
}
