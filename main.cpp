#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  cout << "Argumentos: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }
  cout << "Hello world!" << endl;

  char buf[1000];
  fstream fs("testdata/Covid19Casos.csv", fstream::in);
  while (fs.getline(buf, 1000)) {
    cout << buf;
  }
  fs.close();

  return 0;
}
