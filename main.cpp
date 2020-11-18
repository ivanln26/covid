#include <fstream>
#include <iostream>
#include <sstream>

#include "lib/Arguments.h"
#include "lib/Case.h"
#include "lib/CaseArray.h"
#include "lib/Date.h"
#include "lib/Filters.h"
#include "lib/ProvinceCounter.h"
#include "lib/Statistics.h"

using namespace std;

int countRows(char *filename) {
  int count = 0;
  ifstream ifs(filename);
  string row;
  while (getline(ifs, row)) count++;
  ifs.close();
  return count;
}

int main(int argc, char **argv) {
  Arguments arg;
  arg.parse(argc, argv);

  int n_cases = countRows(arg.getFilename());

  ifstream ifs(arg.getFilename());

  // CSV Reader

  CaseArray cases(n_cases);
  int count = 0;  // counter used for interested fields
  string row, col;
  stringstream ss;
  getline(ifs, row);  // Skip table header
  while (getline(ifs, row)) {
    Case c;
    ss.str(row);
    while (getline(ss, col, ',')) {
      // if (!col.empty()) col = col.substr(1, col.size() - 2); // Too slow
      switch (count) {
        case 0:                                 // id
          col = col.substr(1, col.size() - 2);  // removes "
          c.id = stoi(col);
          count++;
          break;
        case 2:  // age
          count++;
          if (col.empty()) {
            c.age = 0;
            break;
          }
          col = col.substr(1, col.size() - 2);
          c.age = stoi(col);
          break;
        case 3:  // is_years
          col = col.substr(1, col.size() - 2);
          c.is_years = (!col.compare("Años")) ? true : false;
          count++;
          break;
        case 7:  // province_name
          col = col.substr(1, col.size() - 2);
          c.province_name = col;
          count++;
          break;
        case 12:  // is_intensive
          col = col.substr(1, col.size() - 2);
          c.is_intensive = (!col.compare("SI")) ? true : false;
          count++;
          break;
        case 13: {  // intensive_date
          count++;
          if (col.empty()) break;
          col = col.substr(1, col.size() - 2);
          c.intensive_date.fromISO(col);
          break;
        }
        case 14:  // is_dead
          count++;
          if (col.empty()) break;
          col = col.substr(1, col.size() - 2);
          c.is_dead = (!col.compare("NO")) ? false : true;
          break;
        case 20:  // summary
          col = col.substr(1, col.size() - 2);
          c.summary = col;
        default:
          count++;
      }
    }
    count = 0;
    ss.clear();
    cases.append(c);
  }

  // Statistics displayer

  if (arg.getEstad()) {
    printf("\nEstadísticas\n");
    Statistics s;
    s.calculate(cases);
    s.toString();
  }

  if (arg.toCount()) {
    ProvinceCounter pc;
    pc.count(cases);

    printf("\nCasos infectados por provincia\n");
    if (arg.getPCasos() == -1)
      pc.printPInfected();
    else
      pc.printPInfected(arg.getPCasos());

    printf("\nCasos fallecidos por provincia\n");
    if (arg.getPMuertes() == -1)
      pc.printPDeaths();
    else
      pc.printPDeaths(arg.getPMuertes());
  }

  if (arg.getCasosEdad() >= 0) {
    printf("\nCasos por edad\n");
    filters::ageCases(cases, arg.getCasosEdad()).toString();
  }

  if (arg.getCasosCui().getYear() != -1) {
    printf("\nCasos intensivos\n");
    filters::intensiveCases(cases, arg.getCasosCui()).toString();
  }

  ifs.close();

  return 0;
}
