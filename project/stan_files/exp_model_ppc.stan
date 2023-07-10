data {
  int<lower=0> N;                         // Number of observations
  vector[N] mileage;              // Values of the rejects variable
  vector[N] production_year;          // Values of the cycle_times variable
  real<lower=0> mu_a;
  real<lower=0> sig_a;
  real<lower=0> mu_b1;
  real<lower=0> mu_b2;
  real<lower=0> sig_b1;
  real<lower=0> sig_b2;
}

generated quantities {
  vector[N] price;
  real alpha = normal_rng(mu_a, sig_a);
  real beta1 = normal_rng(mu_b1, sig_b1);
  real beta2 = normal_rng(mu_b2, sig_b2);
  real sigma = normal_rng(0.15,0.02);
  real lambda = 1 / normal_rng(40, 0.2);

  for (i in 1:N) {
    real mu = alpha - beta1 * mileage[i] + beta2 * production_year[i];
    price[i] = exponential_rng(mu/lambda);
    // price[i] = normal_rng(alpha + beta1 * mileage[i] + beta2 * production_year[i], sigma);
  }
}