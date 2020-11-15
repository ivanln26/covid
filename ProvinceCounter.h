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
  void quickSort(int *arr, int, int);

 public:
  ProvinceCounter();
  void count(CaseArray);
  void toString();
};

ProvinceCounter::ProvinceCounter() {
  for (int i = 0; i < N_PROVINCES; i++) {
    this->p_infected[i] = 0;
    this->p_deaths[i] = 0;
  }
}

void ProvinceCounter::quickSort(int *arr, int start, int end) {
  int middle = (start + end) / 2;
  int pivot = arr[middle];
  int i = start;
  int j = end;
  int aux;
  string aux_prov;

  do {
    while (arr[i] > pivot) i++;
    while (arr[j] < pivot) j--;

    if (i <= j) {
      aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      aux_prov = provinces[i];
      provinces[i] = provinces[j];
      provinces[j] = aux_prov;
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
  this->quickSort(this->p_infected, 0, N_PROVINCES - 1);
  // this->quickSort(this->p_deaths, 0, N_PROVINCES - 1);
}

void ProvinceCounter::toString() {
  for (int i = 0; i < N_PROVINCES; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_infected[i]);
  }

  /*
  for (int i = 0; i < N_PROVINCES; i++) {
    printf("%s: %d\n", this->provinces[i].c_str(), this->p_deaths[i]);
  }
  */
}

#endif
