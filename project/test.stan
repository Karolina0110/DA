generated quantities {
  real mi = normal_rng(35000, 10000);//chosen 170cm as reasonable mean height of a human, amd standard deviation of 10cm
  real<lower=0> sigma = gamma_rng(10000, 50);
  real prize_sim = normal_rng(mi, sigma);
}