data {
  int<lower=0> N;  // Number of data points
  vector[N] x1;
  vector[N] x2;
}

parameters {
  real<lower=0> alpha;      // Intercept
  real beta1;      // Coefficient for predictor variable 1
  real<lower=0> beta2;      // Coefficient for predictor variable 2
  real<lower=0> sigma;
}

model {
  // Priors
  
  alpha ~ cauchy(10000, 8000);
  beta1 ~ normal(-0.17, 0.05);
  beta2 ~ normal(20, 5);
  sigma ~ normal(0, 10);
}

generated quantities {
  vector[N] y_generated;
  // Generate y_generated based on the new predictor variables
  for (i in 1:N) {
    real lambda = alpha + beta1 * x1[i] + beta2 * x2[i];
    y_generated[i] = poisson_rng(lambda);
  }
}
