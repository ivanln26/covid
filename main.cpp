#include <fstream>
#include <iostream>
#include <sstream>

#include "Arguments.h"
#include "Case.h"
#include "CaseArray.h"
#include "Date.h"
#include "ProvinceCounter.h"
#include "Statistics.h"

using namespace std;

void quickSortAge(CaseArray arr, int start, int end) {
  int middle = (start + end) / 2;
  string pivot = arr[middle].province_name;
  int i = start;
  int j = end;

  do {
    while (arr[i].province_name < pivot) i++;
    while (arr[j].province_name > pivot) j--;

    if (i <= j) {
      arr.swap(i, j);
      i++;
      j--;
    }
  } while (i <= j);

  if (j > start) quickSortAge(arr, start, j);
  if (i < end) quickSortAge(arr, i, end);
}

CaseArray ageCases(CaseArray arr, int age) {
  Case c;
  CaseArray age_cases(arr.getSize());
  for (int i = 0; i < arr.getSize(); i++) {
    c = arr[i];
    if (c.is_years && c.age == age) {
      age_cases.append(c);
    }
  }
  quickSortAge(age_cases, 0, age_cases.getSize() - 1);
  return age_cases;
}

void quickSortIntensive(CaseArray arr, int start, int end) {
  int middle = (start + end) / 2;
  Date pivot = arr[middle].intensive_date;
  int i = start;
  int j = end;

  do {
    while (arr[i].intensive_date < pivot) i++;
    while (arr[j].intensive_date > pivot) j--;

    if (i <= j) {
      arr.swap(i, j);
      i++;
      j--;
    }
  } while (i <= j);

  if (j > start) quickSortIntensive(arr, start, j);
  if (i < end) quickSortIntensive(arr, i, end);
}

CaseArray intensiveCases(CaseArray arr) {
  Case c;
  Date d(2020, 11, 12);
  CaseArray intensive_cases(arr.getSize());
  for (int i = 0; i < arr.getSize(); i++) {
    c = arr[i];
    if (c.is_intensive && c.intensive_date >= d) {
      c.toString();
      intensive_cases.append(c);
    }
  }
  quickSortIntensive(intensive_cases, 0, intensive_cases.getSize() - 1);
  return intensive_cases;
}

int main(int argc, char **argv) {
  Arguments arg;
  arg.parse(argc, argv);

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

  if (arg.getCasosEdad() >= 0) ageCases(cases, arg.getCasosEdad()).toString();

  ifs.close();

  return 0;
}
