#pragma once

#include "HealthResult.h"
#include "TelemetryFrame.h"

class HealthEvaluator {
public:
    // TODO: Evaluate a validated frame using named thresholds.
    HealthResult evaluate(const TelemetryFrame& frame) const;
};
