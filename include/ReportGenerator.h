#pragma once

#include <string>

#include "HealthResult.h"

class ReportGenerator {
public:
    // Format a completed health result without evaluating telemetry.
    std::string generate(const HealthResult& result) const;
};
