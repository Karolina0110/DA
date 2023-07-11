data {
  int<lower=0> N;                         // Number of observations
  vector[N] mileage;              // Values of the mileage variable
  vector[N] production_year;          // Values of the production_year variable
  vector[N] price_observed;           // Observed prices
}

parameters {
  real alpha;
  real beta1;
  real beta2;
  real<lower=0> sigma;
  real<lower=0> lambda;
}

transformed parameters {
  vector[N] mu;
  for (i in 1:N) {
    mu[i] = alpha - beta1 * mileage[i] + beta2 * production_year[i];
  }
}

model {
  alpha ~ normal(0.17, 0.02);
  beta1 ~ normal(0.36, 0.02);
  beta2 ~ normal(0.36, 0.02);
  sigma ~ normal(0.15, 0.02);
  lambda ~ normal(40, 0.2);

  for (i in 1:N) {
    price_observed[i] ~ exponential(mu[i] * lambda);
  }
}

generated quantities {
  vector[N] price_estimated;
  vector[N] log_lik;

  for (i in 1:N) {
    price_estimated[i] = exponential_rng(mu[i] * lambda);
    log_lik[i] = exponential_lpdf(price_observed[i] | (mu[i] * lambda));
  }
}
