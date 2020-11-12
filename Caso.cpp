#include "Caso.h"

Caso::Caso() {}

Caso::Caso(std::string id, std::string edad, std::string edad_anos_meses,
           std::string cuidado_intensivo, std::string fecha_cui_intensivo,
           std::string fallecido, std::string carga_provincia_id,
           std::string clasificacion_resumen) {
  this->id = std::stoi(id);
  if (!edad.empty())
    this->edad = std::stoi(edad);
  else
    this->edad = 0;
  this->edad_anos_meses = (edad_anos_meses.compare("Años") == 0) ? true : false;
  this->cuidado_intensivo =
      (cuidado_intensivo.compare("NO") == 0) ? false : true;
  this->fecha_cui_intensivo = fecha_cui_intensivo;
  this->fallecido = (fallecido.compare("NO") == 0) ? false : true;
  this->carga_provincia_id = std::stoi(carga_provincia_id);
  this->clasificacion_resumen =
      (clasificacion_resumen.compare("Descartado")) ? false : true;
}

bool Caso::getClasificacion() { return this->clasificacion_resumen; }

uint16 Caso::getEdad() {
  if (!this->edad_anos_meses) {
    return 0;
  }
  return this->edad;
}

bool Caso::getFallecido() { return this->fallecido; }

bool Caso::operator>(Caso c) { return this->id > c.id; }

bool Caso::operator<(Caso c) { return this->id < c.id; }

bool Caso::operator==(Caso c) { return this->id == c.id; }

void Caso::toString() {
  printf("| %d ", this->id);
  printf("| %3d ", this->edad);
  printf("| %d ", this->edad_anos_meses);
  printf("| %d ", this->cuidado_intensivo);
  printf("| %10s ", this->fecha_cui_intensivo.c_str());
  printf("| %d ", this->fallecido);
  printf("| %2d ", this->carga_provincia_id);
  printf("| %d |\n", this->clasificacion_resumen);
}
