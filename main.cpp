#include <iostream>

#include "CSVReader.h"
#include "Caso.h"
#include "Contador.h"
#include "Estadistica.h"
#include "ds/AVLTree.h"

using namespace std;

int main(int argc, char **argv) {
  cout << "Argumentos: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }
  cout << "Hello world!" << endl;

  CSVReader r("testdata/Covid19Casos.csv");
  /*
  CSVReader r(
      "C:\\Users\\Tomi\\Desktop\\Programacion 3 "
      "Covid\\testdata\\Covid19Casos-10.csv");
      */

  AVLTree<Caso> casos = r.read();
  // casos.toString();

  Estadistica e(casos.getRoot());
  e.toString();

  Contador c(casos.getRoot());
  c.contarPCasos(24);
  c.contarPMuertes(24);

  return 0;
}
