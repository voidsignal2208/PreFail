#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probability.h"
# include "bayes.h"
#include "risk_state.h"

const char* risk_state_to_string(RiskState state) {
    switch (state) {
        case RISK_SAFE:
            return "SAFE";
        case RISK_WARNING:
            return "WARNING";
        case RISK_CRITICAL:
            return "CRITICAL";
        case RISK_FAILED:
            return "FAILED";
        default:
            return "UNKNOWN";
    }
}

int main() {
       int time_steps = 12;          // simulate 12 time units(eg: for 12 months of year)
       double warning_probability = 0.3;
       double risk = 0.10;   // initial risk
       double decay_factor = 0.95; //Used in risk decay(handling risk>1)

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

    printf("\n=== Bayesian Risk Update ===\n");

    // Initial belief
    double prior_default_risk = 0.10;

    // Evidence: missed payment observed
    double likelihood = 0.7;   // P(missed payment | default risk)
    double evidence = 0.25;    // P(missed payment)

    double updated_risk = bayesian_update(
        prior_default_risk,
        likelihood,
        evidence
    );

    printf("Prior risk: %.2f\n", prior_default_risk);
    printf("Updated risk after warning: %.2f\n", updated_risk);
    RiskState state = classify_risk(updated_risk);

       printf("Risk value: %.2f\n", updated_risk);
       printf("Risk state: %s\n", risk_state_to_string(state));
       
       printf("\n=== Time-Based Risk Simulation ===\n");

       for (int t = 1; t <= time_steps; t++) {
       printf("\nTime step %d\n", t);

       int warning = bernoulli_trial(warning_probability);

       if (warning) {
              printf("Warning detected!\n");

              double likelihood = 0.7;
              double evidence = warning_probability;

              risk = bayesian_update(risk, likelihood, evidence);
       } else {
              printf("No warning. Risk decays.\n");
              risk = risk * decay_factor;
       }
       if (risk > 1.0) {
          risk = 1.0;
       }
       if (risk < 0.0) {
              risk = 0.0;
       }



       RiskState state = classify_risk(risk);

       printf("Risk value: %.2f\n", risk);
       printf("Risk state: %s\n", risk_state_to_string(state));

       if (state == RISK_FAILED) {
              printf("System has FAILED. Stopping simulation.\n");
              break;
       }
       }


    return 0;
}