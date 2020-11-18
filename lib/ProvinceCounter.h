#ifndef PROVINCECOUNTER_H
#define PROVINCECOUNTER_H

#define N_PROVINCES 24

// ProvinceCounter represents an array of provinces with their repective
// conunters
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
  int p_infected[N_PROVINCES];  // infected cases by province
  int p_deaths[N_PROVINCES];    // death cases by province
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

// ProvinceCounter default contructor sets all counters to 0
ProvinceCounter::ProvinceCounter() {
  for (int i = 0; i < N_PROVINCES; i++) {
    this->p_infected[i] = 0;
    this->p_deaths[i] = 0;
  }
}

// swap swaps the province with its counters
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

// quickSort sorts an integer counter array arr from highest to lowest
void ProvinceCounter::quickSort(int *arr, int start, int end) {
  int middle = (start + end) / 2;
  int pivot = arr[middle];
  int i = start, j = end;

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

// count reads a CaseArray arr and checks if it is a confirmed case or a death
// then adds one to the respective province counter
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
}

void ProvinceCounter::printPInfected() {
  this->quickSort(this->p_infected, 0, N_PROVINCES - 1);

  for (int i = 0; i < N_PROVINCES; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_infected[i]);
  }
}

void ProvinceCounter::printPInfected(int n) {
  if (n > N_PROVINCES) n = N_PROVINCES;

  this->quickSort(this->p_infected, 0, N_PROVINCES - 1);

  for (int i = 0; i < n; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_infected[i]);
  }
}

void ProvinceCounter::printPDeaths() {
  this->quickSort(this->p_deaths, 0, N_PROVINCES - 1);

  for (int i = 0; i < N_PROVINCES; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_deaths[i]);
  }
}

void ProvinceCounter::printPDeaths(int n) {
  if (n > N_PROVINCES) n = N_PROVINCES;

  this->quickSort(this->p_deaths, 0, N_PROVINCES - 1);

  for (int i = 0; i < n; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_deaths[i]);
  }
}

#endif
