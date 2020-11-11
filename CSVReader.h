#include <fstream>

#include "ds/List.h"

#ifndef CSVREADER_H
#define CSVREADER_H

class CSVReader {
 private:
  std::ifstream ifs;

 public:
  CSVReader(const char *);
  ~CSVReader();
  List<std::string> *parseRow(std::string);
  List<List<std::string> *> read();
};

#endif
