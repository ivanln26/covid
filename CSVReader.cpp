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

// TODO: remove vector ds
Caso CSVReader::parseRow(std::string row, int *interest, int size) {
  std::vector<std::string> fields;
  std::string col;
  for (char c : row) {
    if (c == '"' || c == '\r') continue;
    if (c == ',') {
      fields.push_back(col);
      col.clear();
      continue;
    }
    col.push_back(c);
  }

  Caso record(fields[interest[0]], fields[interest[1]], fields[interest[2]],
              fields[interest[3]], fields[interest[4]], fields[interest[5]],
              fields[interest[6]], fields[interest[7]], fields[interest[8]]);
  // record.toString();

  return record;
}

AVLTree<Caso> CSVReader::read() {
  int interest[] = {0, 2, 3, 7, 12, 13, 14, 17, 20};
  int size = sizeof(interest) / sizeof(*interest);
  AVLTree<Caso> records;
  std::string row;
  std::getline(this->ifs, row);  // Skip table header
  while (!this->ifs.eof()) {
    std::getline(this->ifs, row);
    if (row.empty()) continue;  // Skip empty row
    records.insert(parseRow(row, interest, size));
  }
  return records;
}
