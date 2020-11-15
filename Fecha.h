#include "iostream"
#include "sstream"

#ifndef CMAKE_COVID_FECHA_H
#define CMAKE_COVID_FECHA_H

class Fecha{
private:
    int dia;
    int mes;
    int ano;
public:
    Fecha();
    Fecha(std::string);
    int getdia();
    int getmes();
    int getano();
    bool operator>(Fecha);
    bool operator<(Fecha);
    bool operator==(Fecha);
    void toString();
};

#endif //CMAKE_COVID_FECHA_H
