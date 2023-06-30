data{
    int<lower=0> N;  // Number of data points
    vector[N] x1_new;
    vector[N] x2_new;
}

parameters {
  real<lower=0> alpha;      // Intercept
  real beta1;      // Coefficient for predictor variable 1
  real<lower=0> beta2;      // Coefficient for predictor variable 2
}

model {
  // Priors
  alpha ~ normal(35000, 1000);
  beta1 ~ normal(-0.4, 0.1);
  beta2 ~ normal(25, 2);
}

generated quantities {
  vector[N] y_generated;

  // Generate y_generated based on the new predictor variables
  for (i in 1:N) {
    y_generated[i] = normal_rng(alpha + beta1 * x1_new[i] + beta2 * x2_new[i], 1);
  }
}

