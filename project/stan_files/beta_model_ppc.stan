data {
  int<lower=0> N;                     // Number of observations
  vector[N] mileage;                  // Values of the mileage variable (normalized)
  vector[N] production_year;          // Values of the production year variable (normalized)
}

parameters {
  real<lower=0> alpha;
  real<lower=0> beta1;
  real<lower=0> beta2;
}

model {
  alpha ~ normal(0.35, 0.05);   // Prior distribution for alpha
  beta1 ~ normal(0.2, 0.05);
  beta2 ~ normal(0.2, 0.05);    // Prior distribution for beta
}

generated quantities {
  vector[N] price;

  for (i in 1:N) {
    real mu = alpha - beta1 * mileage[i] + beta2 * production_year[i];
    price[i] = beta_rng(mu, 1 - mu);
  }
}
