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

  CSVReader r("C:\\Users\\Tomi\\Desktop\\Programacion 3 Covid\\testdata\\Covid19Casos-10.csv");
  List<List<string> *> records = r.read();
  //for (int i = 0; i < records.getSize(); i++) {
    //records[i]->toString();
  //}

    int interest [] = {0, 2, 3, 12, 13, 14, 17, 20};
    int size_interest = sizeof(interest)/sizeof(*interest);

  for (int i=0; i < records.getSize(); i++){
      //printf("%d\n", records.getSize());
      //printf("%d\n", records[i]->getSize());
      for (int j=0; j < size_interest; j++){
         cout<<records[i]->getData(interest [j])<<endl;
      }
      cout<<"---------------------------------"<<endl;
  }

  return 0;
}
