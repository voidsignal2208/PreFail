#include "bayes.h"

// Bayes theorem implementation
double bayesian_update(double prior, double likelihood, double evidence){
    if (evidence == 0.0){
        return prior;  // avoid division by zero
    }

    return (likelihood * prior) / evidence;
}