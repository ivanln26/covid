#include <iostream>

#include "Date.h"

using namespace std;

#ifndef CASE_H
#define CASE_H

class Case {
 public:
  int id;
  int age;
  bool is_years;
  string province_name;
  bool is_intensive;
  Date intensive_date;
  bool is_dead;
  string summary;
  Case();
  void toString();
};

Case::Case() {
  this->id = 0;
  this->age = 0;
  this->is_years = false;
  this->province_name = "";
  this->is_intensive = false;
  this->is_dead = false;
  this->summary = "";
}

void Case::toString() {
  printf("| %7d ", this->id);
  printf("| %3d ", this->age);
  printf("| %d ", this->is_years);
  printf("| %d ", this->is_intensive);
  this->intensive_date.toString();
  // printf("| %10s ", this->intensive_date.c_str());
  printf("| %d ", this->is_dead);
  printf("| %12s ", this->summary.c_str());
  printf("| %20s\n", this->province_name.c_str());
}

#endif
