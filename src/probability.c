#include <stdlib.h>
#include <math.h>
#include "probability.h"

// Simulate a Bernoulli trial
int bernoulli_trial(double p) {
    double r = (double)rand() / RAND_MAX; //a random value between 0 to 1
    return (r < p) ? 1 : 0;
}

// for nCr:
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
    return combination(n, k) * pow(p, k) * pow(1 - p, n - k);//nCk*p^k(1-p)^k
}

// Poisson distribution
double poisson_probability(int k, double lambda) {
    return (pow(lambda, k) * exp(-lambda)) / tgamma(k + 1); //
}

// Exponential distribution
double exponential_probability(double t, double lambda) {
    return lambda * exp(-lambda * t);
}
