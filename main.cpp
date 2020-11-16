#include <fstream>
#include <iostream>
#include <sstream>

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

  /*
  for (int i = 0; i < cases.getSize(); i++) {
    cases[i].toString();
  }

  Statistics s;
  s.calculate(cases);
  s.toString();

  ProvinceCounter pc;
  pc.count(cases);
  pc.toString();
  */

  CaseArray age_cases = ageCases(cases, 20);
  for (int i = 0; i < age_cases.getSize(); i++) {
    age_cases[i].toString();
  }

  /*
  CaseArray intensive_cases = intensiveCases(cases);
  for (int i = 0; i < intensive_cases.getSize(); i++) {
    intensive_cases[i].toString();
  }
  */

  ifs.close();

  return 0;
}
