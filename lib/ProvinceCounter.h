#ifndef PROVINCECOUNTER_H
#define PROVINCECOUNTER_H

#define N_PROVINCES 24

class ProvinceCounter {
 private:
  string provinces[N_PROVINCES] = {
      "Buenos Aires",
      "CABA",
      "Catamarca",
      "Chaco",
      "Chubut",
      "Córdoba",
      "Corrientes",
      "Entre Ríos",
      "Formosa",
      "Jujuy",
      "La Pampa",
      "La Rioja",
      "Mendoza",
      "Misiones",
      "Neuquén",
      "Río Negro",
      "Salta",
      "San Juan",
      "San Luis",
      "Santa Cruz",
      "Santa Fe",
      "Santiago del Estero",
      "Tierra del Fuego",
      "Tucumán",
  };
  int p_infected[N_PROVINCES];
  int p_deaths[N_PROVINCES];
  void swap(int, int);
  void quickSort(int *arr, int, int);

 public:
  ProvinceCounter();
  void count(CaseArray);
  void printPInfected();
  void printPInfected(int);
  void printPDeaths();
  void printPDeaths(int);
};

ProvinceCounter::ProvinceCounter() {
  for (int i = 0; i < N_PROVINCES; i++) {
    this->p_infected[i] = 0;
    this->p_deaths[i] = 0;
  }
}

void ProvinceCounter::swap(int i, int j) {
  int aux;
  std::string province;

  province = this->provinces[i];
  this->provinces[i] = this->provinces[j];
  this->provinces[j] = province;

  aux = this->p_infected[i];
  this->p_infected[i] = this->p_infected[j];
  this->p_infected[j] = aux;

  aux = this->p_deaths[i];
  this->p_deaths[i] = this->p_deaths[j];
  this->p_deaths[j] = aux;
}

void ProvinceCounter::quickSort(int *arr, int start, int end) {
  int i, j, middle;
  int aux, pivot;
  std::string aux_prov;

  middle = (start + end) / 2;
  pivot = arr[middle];
  i = start;
  j = end;

  do {
    while (arr[i] > pivot) i++;
    while (arr[j] < pivot) j--;

    if (i <= j) {
      this->swap(i, j);
      i++;
      j--;
    }
  } while (i <= j);

  if (j > start) this->quickSort(arr, start, j);
  if (i < end) this->quickSort(arr, i, end);
}

void ProvinceCounter::count(CaseArray arr) {
  Case c;
  bool is_province;
  for (int i = 0; i < arr.getSize(); i++) {
    c = arr[i];
    for (int j = 0; j < N_PROVINCES; j++) {
      is_province = c.province_name.compare(this->provinces[j]) == 0;

      if (c.summary.compare("Confirmado") == 0 && is_province) {
        this->p_infected[j]++;
        if (c.is_dead) this->p_deaths[j]++;
        break;
      }

      if (c.is_dead && is_province) {
        this->p_deaths[j]++;
        break;
      }
    }
  }
  // this->quickSort(this->p_infected, 0, N_PROVINCES - 1);
  this->quickSort(this->p_deaths, 0, N_PROVINCES - 1);
}

void ProvinceCounter::printPInfected() {
  for (int i = 0; i < N_PROVINCES; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_infected[i]);
  }
}

void ProvinceCounter::printPInfected(int n) {
  if (n > N_PROVINCES) n = N_PROVINCES;
  for (int i = 0; i < n; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_infected[i]);
  }
}

void ProvinceCounter::printPDeaths() {
  for (int i = 0; i < N_PROVINCES; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_deaths[i]);
  }
}

void ProvinceCounter::printPDeaths(int n) {
  if (n > N_PROVINCES) n = N_PROVINCES;
  for (int i = 0; i < n; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_deaths[i]);
  }
}

#endif