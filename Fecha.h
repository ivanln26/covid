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
    Fecha(std::string);
    bool operator>(Fecha);
    bool operator<(Fecha);
    bool operator==(Fecha);
    void toString();
};

#endif //CMAKE_COVID_FECHA_H
