#include <fstream>
#include <iostream>
#include <sstream>

#include "Case.h"
#include "CaseArray.h"
#include "Statistics.h"
#include "ds/List.h"

using namespace std;

int main(int argc, char **argv) {
  cout << "Argumentos: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }

  ifstream ifs("testdata/Covid19Casos.csv");

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
        case 13:
          count++;
          if (col.empty()) break;
          col = col.substr(1, col.size() - 2);
          c.intensive_date = col;
          break;
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

  /*
  for (int i = 0; i < cases.getSize(); i++) {
    cases[i].toString();
  }
  */

  Statistics s;
  s.calculate(cases);
  s.toString();

  ifs.close();

  return 0;
}
