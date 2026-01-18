#include "risk_state.h"
//It tags a general verbal scale to the numerical calculation of risk
RiskState classify_risk(double risk) {
    if (risk < 0.25) {
        return RISK_SAFE;
    } else if (risk < 0.5) {
        return RISK_WARNING;
    } else if (risk < 0.8) {
        return RISK_CRITICAL;
    } else {
        return RISK_FAILED;
    }
}
