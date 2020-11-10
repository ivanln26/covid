#include "CSVReader.h"

CSVReader::CSVReader(const char *filename) {
  printf("%s\n", filename);
  this->ifs.open(filename);
  if (!this->ifs.good()) {
    printf("No se pudo abrir el archivo: %s\n", filename);
    exit(1);
  }
}

CSVReader::~CSVReader() { this->ifs.close(); }

// TODO: append parsed row to linked list
std::vector<std::string> CSVReader::parseRow(std::string row) {
  std::vector<std::string> record;
  std::string col;
  for (char c : row) {
    if (c == '"') continue;
    if (c == ',') {
      record.push_back(col);
      col.clear();
      continue;
    }
    col.push_back(c);
  }
  record.push_back(col);
  return record;
}

// TODO: return list of parsed rows
void CSVReader::read() {
  std::string row;
  std::getline(this->ifs, row);  // Skip table header
  while (!this->ifs.eof()) {
    printf("---------------\n");
    std::getline(this->ifs, row);
    if (row.empty()) continue;  // Skip empty row
    std::vector<std::string> record = parseRow(row);
    for (std::string r : record) {
      printf("%s\n", r.c_str());
    }
  }
}
