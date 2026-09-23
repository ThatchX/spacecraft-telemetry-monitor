#pragma once

#include "TelemetryFrame.h"

class TelemetryValidator {
public:
    // TODO: Design diagnostics identifying invalid fields and values.
    bool validate(const TelemetryFrame& frame) const;
};
