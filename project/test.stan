generated quantities {
  real alpha;
  real beta1;
  real beta2;
  real mileage;
  real production_year;
  real lambda;
  real price;
  real sigma;

  alpha = normal_rng(10,2);
  beta1 = normal_rng(0, 1);
  beta2 = normal_rng(0, 1);
  sigma = normal_rng(0,1);
  
  mileage = normal_rng(0,1);
  production_year = normal_rng(0,1);


  lambda = exp(alpha + beta1 * mileage + beta2 * production_year);
  price = normal_rng(lambda, sigma);
}
