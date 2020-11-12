#include <fstream>
#include <vector>

#include "Caso.h"
#include "ds/AVLTree.h"

#ifndef CSVREADER_H
#define CSVREADER_H

class CSVReader {
 private:
  std::ifstream ifs;

 public:
  CSVReader(const char *);
  ~CSVReader();
  Caso parseRow(std::string, int *, int);
  AVLTree<Caso> read();
};

#endif
