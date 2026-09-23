#pragma once

#include <string>

#include "HealthResult.h"

class ReportGenerator {
public:
    // TODO: Format structured subsystem results for the caller to display.
    std::string generate(const HealthResult& result) const;
};
