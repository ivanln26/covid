#include "Case.h"
#include "CaseArray.h"

#ifndef FILTERS_H
#define FILTERS_H

namespace filters {
// quickSortAge sorts a CaseArray by province names
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

// ageCases filters a CaseArray arr by age creating a new CaseArray
CaseArray ageCases(CaseArray arr, int age) {
  Case c;
  CaseArray age_cases(arr.getSize());
  for (int i = 0; i < arr.getSize(); i++) {
    c = arr[i];
    if (c.is_years && c.age == age) {
      age_cases.append(c);
    }
  }
  if (age_cases.getSize() > 0)
    quickSortAge(age_cases, 0, age_cases.getSize() - 1);
  return age_cases;
}

// quickSortIntensive sorts a CaseArray by date
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

// intensiveCases filters a CaseArray arr by a greater Date d creating a new
// CaseArray
CaseArray intensiveCases(CaseArray arr, Date d) {
  Case c;
  CaseArray intensive_cases(arr.getSize());
  for (int i = 0; i < arr.getSize(); i++) {
    c = arr[i];
    if (c.is_intensive && c.intensive_date > d) {
      intensive_cases.append(c);
    }
  }
  if (intensive_cases.getSize() > 0)
    quickSortIntensive(intensive_cases, 0, intensive_cases.getSize() - 1);
  return intensive_cases;
}
}  // namespace filters

#endif
