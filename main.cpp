#include <iostream>

#include "CSVReader.h"
#include "Caso.h"
#include "ds/BinaryTree.h"
#include "ds/List.h"

using namespace std;

int main(int argc, char **argv) {
  cout << "Argumentos: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }
  cout << "Hello world!" << endl;

  CSVReader r("testdata/Covid19Casos-10.csv");
  /*
  CSVReader r(
      "C:\\Users\\Tomi\\Desktop\\Programacion 3 "
      "Covid\\testdata\\Covid19Casos-10.csv");
      */
  List<List<string> *> records = r.read();

  int interest[] = {0, 2, 3, 12, 13, 14, 17, 20};
  int size_interest = sizeof(interest) / sizeof(*interest);

  BinaryTree<Caso> casos;

  for (int i = 0; i < records.getSize(); i++) {
    std::string campos[size_interest];
    for (int j = 0; j < size_interest; j++) {
      campos[j] = records[i]->getData(interest[j]);
    }
    Caso caso(campos[0], campos[1], campos[2], campos[3], campos[4], campos[5],
              campos[6], campos[7]);
    // caso.toString();
    casos.insert(caso);
  }

  casos.toString();

  return 0;
}
