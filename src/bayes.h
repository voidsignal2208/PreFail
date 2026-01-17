#ifndef BAYES_H
#define BAYES_H

// Performs Bayesian update
// prior: P(Failure)
// likelihood: P(Evidence | Failure)
// evidence: P(Evidence)
double bayesian_update(double prior,
                       double likelihood,
                       double evidence);

#endif
