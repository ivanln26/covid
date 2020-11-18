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

int main(int argc, char **argv) {
  Arguments arg;
  arg.parse(argc, argv);

  ifstream ifs(arg.getFilename());

  CaseArray cases(4000000);
  int count = 0;
  string row, col;
  stringstream ss;
  getline(ifs, row);  // Skip table header
  while (getline(ifs, row)) {
    Case c;
    ss.str(row);
    while (getline(ss, col, ',')) {
      // if (!col.empty()) col = col.substr(1, col.size() - 2); // Too slow
      switch (count) {
        case 0:
          col = col.substr(1, col.size() - 2);
          c.id = stoi(col);
          count++;
          break;
        case 2:
          count++;
          if (col.empty()) {
            c.age = 0;
            break;
          }
          col = col.substr(1, col.size() - 2);
          c.age = stoi(col);
          break;
        case 3:
          col = col.substr(1, col.size() - 2);
          c.is_years = (!col.compare("Años")) ? true : false;
          count++;
          break;
        case 7:
          col = col.substr(1, col.size() - 2);
          c.province_name = col;
          count++;
          break;
        case 12:
          col = col.substr(1, col.size() - 2);
          c.is_intensive = (!col.compare("SI")) ? true : false;
          count++;
          break;
        case 13: {
          count++;
          if (col.empty()) break;
          col = col.substr(1, col.size() - 2);
          c.intensive_date.fromISO(col);
          break;
        }
        case 14:
          count++;
          if (col.empty()) break;
          col = col.substr(1, col.size() - 2);
          c.is_dead = (!col.compare("NO")) ? false : true;
          break;
        case 20:
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

  if (arg.getEstad()) {
    Statistics s;
    s.calculate(cases);
    s.toString();
  }

  ProvinceCounter pc;
  pc.count(cases);

  if (arg.getPCasos() == -1)
    pc.printPInfected();
  else
    pc.printPInfected(arg.getPCasos());

  if (arg.getPMuertes() == -1)
    pc.printPDeaths();
  else
    pc.printPDeaths(arg.getPMuertes());

  if (arg.getCasosEdad() >= 0)
    filters::ageCases(cases, arg.getCasosEdad()).toString();

  if (arg.getCasosCui().getYear() != -1)
    filters::intensiveCases(cases, arg.getCasosCui()).toString();

  ifs.close();

  return 0;
}
