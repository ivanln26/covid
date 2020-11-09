#include <iostream>

#include "CSVReader.h"

using namespace std;

int main(int argc, char **argv) {
  cout << "Argumentos: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }
  cout << "Hello world!" << endl;

  CSVReader r("testdata/Covid19Casos-10.csv");
  r.read();

  return 0;
}
