#include "Caso.h"

Caso::Caso() {}

Caso::Caso(std::string id, std::string edad, std::string edad_anos_meses,
           std::string cuidado_intensivo, std::string fecha_cui_intensivo,
           std::string fallecido, std::string carga_provincia_id,
           std::string clasificacion_resumen) {
  this->id = std::stoi(id);
  this->edad = std::stoi(edad);
  this->edad_anos_meses = (edad_anos_meses.compare("Años")) ? true : false;
  this->cuidado_intensivo = (cuidado_intensivo.compare("NO")) ? false : true;
  this->fecha_cui_intensivo = fecha_cui_intensivo;
  this->fallecido = (fallecido.compare("NO")) ? false : true;
  this->carga_provincia_id = std::stoi(carga_provincia_id);
  this->clasificacion_resumen =
      (clasificacion_resumen.compare("Descartado")) ? false : true;
}

bool Caso::get_clasificacion(){return this->clasificacion_resumen}

bool Caso::get_fallecido(){return this->get_fallecido()}

bool Caso::operator>(Caso c) { return this->id > c.id; }

bool Caso::operator<(Caso c) { return this->id < c.id; }

bool Caso::operator==(Caso c) { return this->id == c.id; }

void Caso::toString() {
  printf("| %d ", this->id);
  printf("| %2d ", this->edad);
  printf("| %d ", this->edad_anos_meses);
  printf("| %d ", this->cuidado_intensivo);
  printf("| %10s ", this->fecha_cui_intensivo.c_str());
  printf("| %d ", this->fallecido);
  printf("| %2d ", this->carga_provincia_id);
  printf("| %d |\n", this->clasificacion_resumen);
}
