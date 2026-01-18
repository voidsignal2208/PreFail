# PreFail
PreFail is a probabilistic early-warning system written in C that predicts failure risk over time using Bayesian inference and Monte Carlo simulation.
**Key features:**
- Pure probabilistic modeling (no machine learning)
- Bayesian risk updating with early warning signs
- Time-based risk evolution with decay
- Monte Carlo simulation for failure forecasting

The system intentionally avoids machine learning in favor of transparent probabilistic reasoning, making its predictions interpretable and suitable for low-data or constrained environments.

## Problem Statement
In real-world systems such as financial platforms and computer networks, failures rarely occur suddenly. 
They are usually preceded by early warning signs like missed payments, increasing error rates, or intermittent instability.

Most systems either react after failure has already occurred or rely on heavy machine learning models that require large datasets.
This makes early risk prediction difficult, opaque, or impractical in constrained environments.

PreFail addresses this gap by modeling uncertainty directly using probability theory, allowing risk to be estimated and updated
before a system actually fails.
## High-Level Approach
PreFail models failure risk as a probabilistic belief that evolves over time rather than as a fixed prediction.

At each time step, the system observes whether an early warning sign occurs.
These warning signs are treated as stochastic events and are modeled using probability distributions.
When a warning is observed, PreFail updates its belief about failure risk using Bayesian inference.
When no warning is observed, the risk gradually decays to reflect increasing confidence in system stability.

This evolving risk is then mapped to interpretable system states such as SAFE, WARNING, CRITICAL, and FAILED.
By simulating this process repeatedly using Monte Carlo methods, PreFail estimates both the probability of failure
within a given time horizon and the expected time to failure.
## Core Components
PreFail is structured as a set of focused components, each responsible for a specific part of the risk modeling process.

### Probability Engine
Implements core probability distributions such as Bernoulli, Binomial, Poisson, and Exponential distributions.
These are used to model the occurrence, frequency, and timing of early warning signals.

### Bayesian Update Module
Applies Bayesian inference to update the system’s belief about failure risk whenever new evidence (warning signs) is observed.
This allows risk to evolve dynamically as new information becomes available.

### Risk State Classifier
Converts numerical risk values into interpretable system states: SAFE, WARNING, CRITICAL, and FAILED.
This makes probabilistic outputs understandable and actionable.

### Time-Based Simulation
Simulates the evolution of risk over discrete time steps.
Risk increases when warning signs occur and decays gradually during stable periods.

### Monte Carlo Simulation
Runs the time-based simulation repeatedly across many randomized futures.
This is used to estimate the probability of failure within a given time horizon and the expected time to failure.
## Sample Output
A typical execution of PreFail produces output similar to the following:

=== Time-Based Risk Simulation ===

Time step 1
No warning. Risk decays.
Risk value: 0.10
Risk state: SAFE

Time step 4
Warning detected!
Risk value: 0.49
Risk state: WARNING

Time step 6
Warning detected!
Risk value: 1.00
Risk state: FAILED
System has FAILED. Stopping simulation.

=== Monte Carlo Failure Prediction ===
Simulations run: 1000
Failures observed: 747
Probability of failure within 12 steps: 0.747
Average time to failure: 7.72 steps

The time-based simulation shows how risk evolves step by step.
Risk increases when warning signs occur and decays gradually during stable periods.
Once the risk reaches a critical threshold, the system is classified as FAILED and the simulation stops.

The Monte Carlo simulation aggregates many such runs to estimate overall system behavior.
It reports the probability that the system will fail within a fixed time horizon and the average time at which failure occurs.
This provides a forward-looking, probabilistic assessment of system reliability rather than a single deterministic outcome.
## How to Build and Run
PreFail is written in standard C and does not depend on any external libraries.

### Requirements
- GCC (or any C compiler)
- A standard C development environment

### Build
From the project root directory, compile the project using:

```bash
gcc src/main.c src/probability.c src/bayes.c src/risk_state.c -o prefail -lm
```

### Run
After compilation, run the executable:
```bash
./prefail
```
This project demonstrates how probabilistic reasoning and simulation can be used to predict system failures without relying on machine learning models.


