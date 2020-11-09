#include <fstream>

#ifndef CSVREADER_H
#define CSVREADER_H

class CSVReader {
 private:
  std::ifstream ifs;

 public:
  CSVReader(const char *);
  ~CSVReader();
  void parseRow(std::string);
  void read();
};

#endif
