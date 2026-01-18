#ifndef RISK_STATE_H
#define RISK_STATE_H

// Represents the overall risk level of the system
typedef enum {
    RISK_SAFE,
    RISK_WARNING,
    RISK_CRITICAL,
    RISK_FAILED
} RiskState;

// Classifies numerical risk into a risk state
RiskState classify_risk(double risk);

#endif