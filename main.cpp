#include <iostream>

#include "CSVReader.h"
#include "ds/List.h"

using namespace std;

int main(int argc, char **argv) {
  cout << "Argumentos: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }
  cout << "Hello world!" << endl;

  CSVReader r("testdata/Covid19Casos-10.csv");
  List<List<string> *> records = r.read();
  for (int i = 0; i < records.getSize(); i++) {
    records[i]->toString();
  }

  return 0;
}
