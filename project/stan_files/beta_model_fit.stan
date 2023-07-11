data {
  int<lower=0> N;  // Number of data points
  vector[N] mileage;  // Normalized mileage values
  vector[N] production_year;  // Normalized production year values
  vector[N] price_observed;
}

parameters{
  real alpha;
  real beta1;
  real beta2;
}

transformed parameters {
  vector[N] lambda;
  for (i in 1:N) {
    lambda[i] = inv_logit(alpha + beta1 * mileage[i] + beta2 * production_year[i]);
  }
}

model{
  alpha ~ normal(-1, 0.5);
  beta1 ~ normal(1, 0.1);
  beta2 ~ normal(0.5, 0.1);

  for (i in 1:N){
    price_observed[i] ~ beta(lambda[i] * 10, (1 - lambda[i]) * 30);
  }
}

generated quantities {
  vector[N] price_estimated;
  vector[N] log_likelihood;
  
  for (i in 1:N) {
    price_estimated[i] = beta_rng(lambda[i] * 10, (1 - lambda[i]) * 30);
    log_likelihood[i] = beta_lpdf(price_observed[i] | lambda[i] * 10, (1 - lambda[i]) * 30);
  }
}
