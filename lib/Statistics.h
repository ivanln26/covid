#ifndef STATISTICS_H
#define STATISTICS_H

#define N_AGE_RANGE 14

class Statistics {
 private:
  int n_samples;
  int n_infected;
  int n_deaths;
  float pt_infected;
  float pt_deaths;
  int *n_infected_age;
  int *n_deaths_age;

 public:
  Statistics();
  ~Statistics();
  void calculate(CaseArray);
  void toString();
};

Statistics::Statistics() {
  this->n_samples = 0;
  this->n_infected = 0;
  this->n_deaths = 0;
  this->pt_infected = 0;
  this->pt_deaths = 0;
  this->n_infected_age = new int[N_AGE_RANGE];
  this->n_deaths_age = new int[N_AGE_RANGE];
  for (int i = 0; i < N_AGE_RANGE; i++) {
    this->n_infected_age[i] = 0;
    this->n_deaths_age[i] = 0;
  }
}

Statistics::~Statistics() {
  delete this->n_infected_age;
  delete this->n_deaths_age;
  this->n_infected_age = NULL;
  this->n_deaths_age = NULL;
}

void Statistics::calculate(CaseArray arr) {
  Case c;
  int age_range;
  this->n_samples = arr.getSize();
  for (int i = 0; i < arr.getSize(); i++) {
    c = arr[i];
    age_range = arr[i].age / 10;
    if (!arr[i].is_years) age_range = 0;
    if (c.summary.compare("Confirmado") == 0) {
      this->n_infected++;
      this->n_infected_age[age_range]++;
    }
    if (c.is_dead) {
      this->n_deaths++;
      this->n_deaths_age[age_range]++;
    }
  }
  this->pt_infected = (float)this->n_infected / this->n_samples * 100;
  this->pt_deaths = (float)this->n_deaths / this->n_infected * 100;
}

void Statistics::toString() {
  printf("N of cases: %d\n", this->n_samples);
  printf("N of infected: %d\n", this->n_infected);
  printf("N of deaths: %d\n", this->n_deaths);
  printf("Infected: %.2f %%\n", this->pt_infected);
  printf("Death: %.2f %%\n", this->pt_deaths);

  printf("Infected by age: [");
  for (int i = 0; i < N_AGE_RANGE; i++) {
    printf(" %d", this->n_infected_age[i]);
  }
  printf(" ]\n");

  printf("Deaths by age: [");
  for (int i = 0; i < N_AGE_RANGE; i++) {
    printf(" %d", this->n_deaths_age[i]);
  }
  printf(" ]\n");
}

#endif
