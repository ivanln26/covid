#include <stdio.h>
#include <string.h>

#include "Date.h"

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

// Arguments represents all the arguments used in the program.
class Arguments {
 private:
  char *filename;
  bool estad;
  int p_casos;
  int p_muertes;
  int casos_edad;
  Date casos_cui;
  bool to_count;
  bool hasCSV(char *);
  bool checkDate(char *);
  bool checkNext(char *);
  bool isNumber(char);

 public:
  Arguments();
  void parse(int, char **);
  char *getFilename();
  bool getEstad();
  int getPCasos();
  int getPMuertes();
  int getCasosEdad();
  Date getCasosCui();
  bool toCount();
};

// Arguments contructor used to set flag defaults
Arguments::Arguments() {
  this->estad = false;
  this->p_casos = 0;
  this->p_muertes = 0;
  this->casos_edad = -1;
  this->casos_cui = Date(-1, -1, -1);
  this->to_count = false;
}

// hasCSV reports whether a string has the .csv extension
bool Arguments::hasCSV(char *str) {
  size_t str_l = strlen(str);

  const char *suffix = ".csv";
  size_t suffix_l = strlen(suffix);

  if (suffix_l > str_l) exit(1);

  return strncmp(str + str_l - suffix_l, suffix, suffix_l) == 0;
}

// checkDate reports whether a string is a date in ISO 8601 format
bool Arguments::checkDate(char *str) {
  size_t size = strlen(str);

  if (size != 10) return false;

  std::string a = string(str);
  std::string years = a.substr(0, 4);
  std::string month = a.substr(5, 2);
  std::string day = a.substr(8, 2);

  for (char c : years) {
    if (!this->isNumber(c)) return false;
  }

  for (char c : month) {
    if (!this->isNumber(c)) return false;
  }

  for (char c : day) {
    if (!this->isNumber(c)) return false;
  }

  return true;
}

// checkNext reports whethera string is valid to use as an option for an
// argument
bool Arguments::checkNext(char *str) {
  size_t size = strlen(str);
  for (int i = 0; i < size; i++) {
    if (!this->isNumber(str[i])) return false;
  }
  return true;
}

// isNumber reports if a character is a number
bool Arguments::isNumber(char c) {
  return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
         c == '6' || c == '7' || c == '8' || c == '9';
}

// parse reads an interpret command line arguments
void Arguments::parse(int argc, char **argv) {
  if (argc < 2) {
    printf("Pocos argumentos\n");
    exit(1);
  }

  char *str = argv[argc - 1];  // the last argument must be a csv file
  if (!this->hasCSV(str)) {
    printf("%s no es un archivo CSV\n", str);
    exit(1);
  }
  this->filename = str;

  char *next;
  for (int i = 1; i < argc - 1; i++) {
    if (argv[i][0] == '-') {
      if (strcmp(argv[i], "-estad") == 0) {
        this->estad = true;
        continue;
      }

      next = argv[i + 1];

      if (strcmp(argv[i], "-p_casos") == 0) {
        this->to_count = true;
        if (this->checkNext(next))
          this->p_casos = atoi(next);
        else
          this->p_casos = -1;
        continue;
      }

      if (strcmp(argv[i], "-p_muertes") == 0) {
        this->to_count = true;
        if (this->checkNext(next))
          this->p_muertes = atoi(next);
        else
          this->p_muertes = -1;
        continue;
      }

      if (strcmp(argv[i], "-casos_edad") == 0 && this->checkNext(next)) {
        this->casos_edad = atoi(next);
        continue;
      }

      if (strcmp(argv[i], "-casos_cui") == 0) {
        if (this->checkDate(next))
          this->casos_cui.fromISO(next);
        else
          printf("%s No es una fecha válida\n", next);
        continue;
      }
    }
  }
}

char *Arguments::getFilename() { return this->filename; }

bool Arguments::getEstad() { return this->estad; }

int Arguments::getPCasos() { return this->p_casos; }

int Arguments::getPMuertes() { return this->p_muertes; }

int Arguments::getCasosEdad() { return this->casos_edad; }

Date Arguments::getCasosCui() { return this->casos_cui; }

bool Arguments::toCount() { return this->to_count; }

#endif
