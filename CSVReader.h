#include <fstream>
#include <vector>

#ifndef CSVREADER_H
#define CSVREADER_H

class CSVReader {
 private:
  std::ifstream ifs;

 public:
  CSVReader(const char *);
  ~CSVReader();
  std::vector<std::string> parseRow(std::string);
  void read();
};

#endif
