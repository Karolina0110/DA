data {
  int<lower=0> N;  // Number of data points
  vector[N] x1;
  vector[N] x2;
  vector[N] y;
}

parameters {
  real<lower=0> alpha;      // Intercept
  real beta1;      // Coefficient for predictor variable 1
  real<lower=0> beta2;      // Coefficient for predictor variable 2
  real<lower=0> sigma;
  vector[N] lambda;
}

model {
  // Priors
  
  alpha ~ normal(20000, 1000);
  beta1 ~ normal(-0.17, 0.01);
  beta2 ~ normal(20, 3);
  sigma ~ normal(0, 10);

  // Likelihood
  for (i in 1:N) {
    lambda[i] ~ normal(alpha + beta1 * x1[i] + beta2 * x2[i], sigma);
    y[i] ~ poisson(fabs(lambda[i]));
  }
}

generated quantities {
  vector[N] y_generated;
  vector[N] log_lik;

  // Generate y_generated based on the new predictor variables
  for (i in 1:N) {
    real lambda = fabs(normal_rng(alpha + beta1 * x1[i] + beta2 * x2[i], sigma));
    y_generated[i] = poisson_rng(lambda);
    log_lik[i] = poisson_lpmf(y[i] | lambda);
  }
}
