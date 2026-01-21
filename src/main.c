#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probability.h"
# include "bayes.h"
#include "risk_state.h"

const char* risk_state_to_string(RiskState state){
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
void run_probability_tests(void){
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
}
void run_bayesian_demo(void){
    printf("\n=== Bayesian Risk Update ===\n");

    // Initial belief
    double prior_default_risk = 0.10;

    double likelihood = 0.7;   
    double evidence = 0.25;    

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

}
void run_time_simulation(void) {
    printf("\n=== Time-Based Risk Simulation ===\n");

    int time_steps = 12;
    double warning_probability = 0.3;
    double decay_factor = 0.95;
    double risk = 0.10;

    for (int t = 1; t <= time_steps; t++) {
        printf("\nTime step %d\n", t);

        int warning = bernoulli_trial(warning_probability);

        if (warning){
            printf("Warning detected!\n");

            double likelihood = 0.7;
            double evidence = warning_probability;
            risk = bayesian_update(risk, likelihood, evidence);
        } else{
            printf("No warning. Risk decays.\n");
            risk *= decay_factor;
        }

        if (risk > 1.0) risk = 1.0;
        if (risk < 0.0) risk = 0.0;

        RiskState state = classify_risk(risk);

        printf("Risk value: %.2f\n", risk);
        printf("Risk state: %s\n", risk_state_to_string(state));

        if (state == RISK_FAILED){
            printf("System has FAILED. Stopping simulation.\n");
            break;
        }
    }
}

void run_monte_carlo(void){
    printf("\n=== Monte Carlo Failure Prediction ===\n");

    int simulations = 1000;
    int max_time_steps = 12;
    double warning_probability = 0.3;
    double decay_factor = 0.95;

    int failures = 0;
    int total_failure_time = 0;

    for (int s = 0; s < simulations; s++){
        double risk = 0.10;

        for (int t = 1; t <= max_time_steps; t++){
            int warning = bernoulli_trial(warning_probability);

            if (warning){
                double likelihood = 0.7;
                double evidence = warning_probability;
                risk = bayesian_update(risk, likelihood, evidence);
            } else{
                risk *= decay_factor;
            }

            if (risk > 1.0) risk = 1.0;
            if (risk < 0.0) risk = 0.0;

            if (classify_risk(risk) == RISK_FAILED){
                failures++;
                total_failure_time += t;
                break;
            }
        }
    }

    double failure_probability = (double)failures/simulations;

    printf("Simulations run: %d\n", simulations);
    printf("Failures observed: %d\n", failures);
    printf("Probability of failure within %d steps: %.3f\n",
           max_time_steps, failure_probability);

    if (failures > 0) {
        printf("Average time to failure: %.2f steps\n",
               (double)total_failure_time / failures);
    }
}

int main(void){
    srand(time(NULL));

    run_probability_tests();
    run_bayesian_demo();
    run_time_simulation();
    run_monte_carlo();

    return 0;
}