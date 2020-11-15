#include <fstream>
#include <iostream>
#include <sstream>

#include "ds/List.h"

using namespace std;

typedef struct {
  int id;
  int age;
  bool is_years;
  string province_name;
  bool is_intensive;
  string intensive_date;
  bool is_dead;
  string summary;
} Case;

Case new_case() {
  Case c;
  c.id = 0;
  c.age = 0;
  c.is_years = false;
  c.province_name = "";
  c.is_intensive = false;
  c.intensive_date = "";
  c.is_dead = false;
  c.summary = "";
  return c;
}

void print_case(Case c) {
  printf("| %7d ", c.id);
  printf("| %3d ", c.age);
  printf("| %d ", c.is_years);
  printf("| %20s ", c.province_name.c_str());
  printf("| %d ", c.is_intensive);
  printf("| %10s ", c.intensive_date.c_str());
  printf("| %d ", c.is_dead);
  printf("| %12s |\n", c.summary.c_str());
}

int main(int argc, char **argv) {
  cout << "Argumentos: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }

  ifstream ifs("testdata/Covid19Casos.csv");

  List<Case> cases;
  int count = 0;
  string row, col;
  stringstream ss;
  getline(ifs, row);  // Skip table header
  while (getline(ifs, row)) {
    Case c = new_case();
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
    cases.prepend(c);
  }

  ifs.close();

  return 0;
}
