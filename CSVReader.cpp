#include "CSVReader.h"

#include "stdio.h"

CSVReader::CSVReader(const char *filename) {
  printf("%s\n", filename);
  this->ifs.open(filename);
  if (!this->ifs.good()) {
    printf("No se pudo abrir el archivo: %s\n", filename);
    exit(1);
  }
}

CSVReader::~CSVReader() { this->ifs.close(); }

// TODO: parse last column
// TODO: append parsed row to list
void CSVReader::parseRow(std::string row) {
  std::string col;
  for (char c : row) {
    if (c == '"') continue;
    if (c == ',') {
      printf("%s\n", col.c_str());
      col.clear();
      continue;
    }
    col.push_back(c);
  }
}

// TODO: return list of parsed rows
void CSVReader::read() {
  std::string row;
  std::getline(this->ifs, row);  // Skip table header
  while (!this->ifs.eof()) {
    std::getline(this->ifs, row);
    parseRow(row);
    printf("---------------\n");
  }
}
