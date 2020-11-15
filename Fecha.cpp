#include "Fecha.h"

Fecha::Fecha() {}

//2020-06-01
//2020
Fecha::Fecha(std::string fecha) {
    std::stringstream flujo(fecha);
    std::string dato;
    std::getline(flujo, dato, '-');
    this->ano = std::stoi(dato);
    std::getline(flujo, dato, '-');
    this->mes = std::stoi(dato);
    std::getline(flujo, dato, '-');
    this->dia =std::stoi(dato);
}

void Fecha::toString() {
    std::cout<<ano<<"/"<<mes<<"/"<<dia<<std::endl;
}

bool Fecha::operator<(Fecha f) {
    if (this->ano < f.ano){
        return true;
    }
    if (this->mes < f.mes){
        return true;
    }
    if (this->dia < f.dia){
        return true;
    }
    return false;
}

bool Fecha::operator>(Fecha f) {
    if (this->ano > f.ano){
        return true;
    }
    if (this->mes > f.mes){
        return true;
    }
    if (this->dia > f.dia){
        return true;
    }
    return false;
}

bool Fecha::operator==(Fecha f) {
    if (this->ano != f.ano){
        return false;
    }
    if (this->mes != f.mes){
        return false;
    }
    if (this->dia != f.dia){
        return false;
    }
    return true;
}

int Fecha::getano() {
    return this->ano;
}

int Fecha::getmes() {
    return this->mes;
}

int Fecha::getdia() {
    return this->dia;
}