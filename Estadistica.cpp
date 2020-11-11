#include "iostream"
#include "Estadistica.h"

using namespace std;

Estadistica::Estadistica(int n_muestras, int n_infectados, int n_fallecidos, float porcentaje_infectados, float porcentaje_fallecidos, int *n_infectados_edad, int *n_fallecidos_edad) {
    this->n_muestras = n_muestras;
    this->n_infectados = n_infectados;
    this->n_fallecidos = n_fallecidos;
    this->porcentaje_infectados = porcentaje_infectados;
    this->porcentaje_fallecidos = porcentaje_fallecidos;
    this->n_infectados_edad = NULL;
    this->n_fallecidos_edad = NULL;
}

