data {
  int<lower=0> N;  // Number of data points
  vector[N] x1;    // Predictor variable 1 (mileage)
  vector[N] x2;    // Predictor variable 2 (production year)
  vector[N] y;     // Target variable (price)
}

parameters {
  real<lower=0> alpha;      // Intercept
  real beta1;      // Coefficient for predictor variable 1
  real<lower=0> beta2;      // Coefficient for predictor variable 2
  real<lower=0> sigma;
}

model {
  // Priors
  alpha ~ normal(35000, 1000);
  beta1 ~ normal(-0.17, 0.02);
  beta2 ~ normal(20, 3);
  sigma ~ normal(0, 10);
  
  // Likelihood
  y ~ normal(alpha + beta1 * x1 + beta2 * x2, sigma);
}

generated quantities {
  vector[N] y_generated;
  for (i in 1:N) {
    y_generated[i] = normal_rng(alpha + beta1 * x1[i] + beta2 * x2[i], sigma);
  }
}