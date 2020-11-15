#include <iostream>
#include <sstream>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date {
 private:
  int year;
  int month;
  int day;

 public:
  Date();
  Date(int, int, int);
  void fromISO(string);
  bool operator>(Date);
  bool operator<(Date);
  bool operator==(Date);
  bool operator>=(Date);
  void toString();
};

Date::Date() {
  this->year = 0;
  this->month = 0;
  this->day = 0;
}

Date::Date(int year, int month, int day) {
  this->year = year;
  this->month = month;
  this->day = day;
}

void Date::fromISO(string date_s) {
  stringstream ss(date_s);
  string data;
  getline(ss, data, '-');
  this->year = stoi(data);
  getline(ss, data, '-');
  this->month = stoi(data);
  getline(ss, data, '-');
  this->day = stoi(data);
}

bool Date::operator>(Date d) {
  if (this->year > d.year) return true;
  if (this->year < d.year) return false;
  if (this->month > d.month) return true;
  if (this->month < d.month) return false;
  if (this->day > d.day) return true;
  if (this->day < d.day) return false;
  return false;
}

bool Date::operator<(Date d) {
  if (this->year < d.year) return true;
  if (this->year > d.year) return false;
  if (this->month < d.month) return true;
  if (this->month > d.month) return false;
  if (this->day < d.day) return true;
  if (this->day > d.day) return false;
  return false;
}

bool Date::operator==(Date d) {
  return this->year == d.year && this->month == d.month && this->day == d.day;
}

bool Date::operator>=(Date d) {
  if (this->year > d.year) return true;
  if (this->year < d.year) return false;
  if (this->month > d.month) return true;
  if (this->month < d.month) return false;
  if (this->day > d.day) return true;
  if (this->day < d.day) return false;
  return true;
}

void Date::toString() {
  printf("| %4d/%02d/%02d ", this->year, this->month, this->day);
}

#endif
