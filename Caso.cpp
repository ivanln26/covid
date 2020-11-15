#include "Caso.h"

Caso::Caso() {}

Caso::Caso(std::string id, std::string edad, std::string edad_anos_meses,
           std::string carga_provincia_nombre, std::string cuidado_intensivo,
           std::string fecha_cui_intensivo, std::string fallecido,
           std::string carga_provincia_id, std::string clasificacion_resumen) {
  this->id = std::stoi(id);
  if (!edad.empty())
    this->edad = std::stoi(edad);
  else
    this->edad = 0;
  this->edad_anos_meses = (edad_anos_meses.compare("Años") == 0) ? true : false;
  this->carga_provincia_nombre = carga_provincia_nombre;
  this->cuidado_intensivo =
      (cuidado_intensivo.compare("NO") == 0) ? false : true;
  if (!fecha_cui_intensivo.empty()) this->fecha_cui_intensivo = new Fecha(fecha_cui_intensivo);
  else this->fecha_cui_intensivo = NULL;
  this->fallecido = (fallecido.compare("NO") == 0) ? false : true;
  this->carga_provincia_id = std::stoi(carga_provincia_id);
  this->clasificacion_resumen =
      (clasificacion_resumen.compare("Descartado") == 0) ? false : true;
}

bool Caso::getClasificacion() { return this->clasificacion_resumen; }

uint16 Caso::getEdad() {
  if (!this->edad_anos_meses) {
    return 0;
  }
  return this->edad;
}

bool Caso::getFallecido() { return this->fallecido; }

std::string Caso::getProvincia() { return this->carga_provincia_nombre; }

bool Caso::getCuidado_intensivo() { return this->cuidado_intensivo; }

bool Caso::operator>(Caso c) { return this->id > c.id; }

bool Caso::operator<(Caso c) { return this->id < c.id; }

bool Caso::operator==(Caso c) { return this->id == c.id; }

void Caso::toString() {
  printf("| %d ", this->id);
  printf("| %3d ", this->edad);
  printf("| %d ", this->edad_anos_meses);
  printf("| %19s ", this->carga_provincia_nombre.c_str());
  printf("| %d ", this->cuidado_intensivo);
  if (this->fecha_cui_intensivo != NULL) {
      printf("| %4d/%02d/%02d ", this->fecha_cui_intensivo->getano(),this->fecha_cui_intensivo->getmes(),this->fecha_cui_intensivo->getdia());
  } else printf("| %10s " , " ");
  printf("| %d ", this->fallecido);
  printf("| %2d ", this->carga_provincia_id);
  printf("| %d |\n", this->clasificacion_resumen);
}

