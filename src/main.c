#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probability.h"

int main() {
    // Seed random number generator
    srand(time(NULL));

    printf("=== PreFail Probability Test ===\n\n");

    // Bernoulli trial
    printf("Bernoulli Trial (p = 0.3): %d\n",
           bernoulli_trial(0.3));

    // Binomial probability
    printf("Binomial Probability (n=10, k=3, p=0.2): %.5f\n",
           binomial_probability(10, 3, 0.2));

    // Poisson probability
    printf("Poisson Probability (k=2, lambda=1.5): %.5f\n",
           poisson_probability(2, 1.5));

    // Exponential probability
    printf("Exponential Probability (t=2, lambda=0.5): %.5f\n",
           exponential_probability(2.0, 0.5));

    return 0;
}