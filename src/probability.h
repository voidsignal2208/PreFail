#ifndef PROBABILITY_H
#define PROBABILITY_H

// Returns 1 with probability p, else 0
int bernoulli_trial(double p);

// Probability of k successes in n trials
double binomial_probability(int n, int k, double p);

// Poisson probability for k events
double poisson_probability(int k, double lambda);

// Exponential distribution (time to event)
double exponential_probability(double t, double lambda);

#endif