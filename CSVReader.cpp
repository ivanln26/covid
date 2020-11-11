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

List<std::string> *CSVReader::parseRow(std::string row) {
  List<std::string> *record = new List<std::string>;
  std::string col;
  for (char c : row) {
    if (c == '"' || c == '\r') continue;
    if (c == ',') {
      record->append(col);
      col.clear();
      continue;
    }
    col.push_back(c);
  }
  record->append(col);
  return record;
}

List<List<std::string> *> CSVReader::read() {
  List<List<std::string> *> records;
  std::string row;
  std::getline(this->ifs, row);  // Skip table header
  while (!this->ifs.eof()) {
    std::getline(this->ifs, row);
    if (row.empty()) continue;  // Skip empty row
    records.append(parseRow(row));
  }
  return records;
}
