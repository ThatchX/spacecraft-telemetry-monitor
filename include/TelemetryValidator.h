#pragma once

#include "TelemetryFrame.h"

#include <string>
#include <vector>

// Describe one impossible input while preserving its original value.
struct ValidationIssue {
    std::string fieldName;
    double value{};
    std::string message;
};

struct ValidationResult {
    std::vector<ValidationIssue> issues;

    // A frame is valid only when no field-level issues were collected.
    bool isValid() const {
        return issues.empty();
    }
};

class TelemetryValidator {
public:
    // Return every issue so callers can correct a frame in one pass.
    ValidationResult validate(const TelemetryFrame& frame) const;
};
