#include <iostream>

#ifndef CASO_H
#define CASO_H

typedef unsigned short int uint16;
typedef unsigned int uint32;

class Caso {
 private:
  uint32 id;
  uint16 edad;
  bool edad_anos_meses;
  std::string carga_provincia_nombre;
  bool cuidado_intensivo;
  std::string fecha_cui_intensivo;  // TODO: date class
  bool fallecido;
  uint16 carga_provincia_id;
  bool clasificacion_resumen;

 public:
  Caso();
  Caso(std::string, std::string, std::string, std::string, std::string,
       std::string, std::string, std::string, std::string);
  bool getClasificacion();
  uint16 getEdad();
  bool getFallecido();
  std::string getProvincia();
  bool operator>(Caso);
  bool operator<(Caso);
  bool operator==(Caso);
  void toString();
};

#endif
