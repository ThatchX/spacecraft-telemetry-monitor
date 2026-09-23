#pragma once

#include "HealthResult.h"
#include "TelemetryFrame.h"

class HealthEvaluator {
public:
    // Evaluate subsystem health after the frame has passed validation.
    HealthResult evaluate(const TelemetryFrame& frame) const;
};
