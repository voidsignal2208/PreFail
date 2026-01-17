#include <stdlib.h>
#include <math.h>
#include "probability.h"

// Simulate a Bernoulli trial
int bernoulli_trial(double p) {
    double r = (double)rand() / RAND_MAX;
    return (r < p) ? 1 : 0;
}

// Compute n choose k
static double combination(int n, int k) {
    double result = 1.0;
    for (int i = 1; i <= k; i++) {
        result *= (n - k + i);
        result /= i;
    }
    return result;
}

// Binomial distribution
double binomial_probability(int n, int k, double p) {
    return combination(n, k) * pow(p, k) * pow(1 - p, n - k);
}

// Poisson distribution
double poisson_probability(int k, double lambda) {
    return (pow(lambda, k) * exp(-lambda)) / tgamma(k + 1);
}

// Exponential distribution
double exponential_probability(double t, double lambda) {
    return lambda * exp(-lambda * t);
}
