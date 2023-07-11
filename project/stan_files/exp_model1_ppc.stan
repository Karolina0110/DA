data {
  int<lower=0> N;                         // Number of observations
  vector[N] mileage;              // Values of the rejects variable
  vector[N] production_year;          // Values of the cycle_times variable
}

generated quantities {
  vector[N] price;
  real alpha = normal_rng(0.17, 0.02);
  real beta = normal_rng(0.36, 0.02);
  real sigma = normal_rng(0.15, 0.02);
  real lambda = normal_rng(40, 0.2);

  for (i in 1:N) {
    real mu = alpha + beta * production_year[i];
    price[i] = exponential_rng(mu * lambda);
  }
}
