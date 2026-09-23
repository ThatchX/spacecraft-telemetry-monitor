#include "TelemetryValidator.h"

ValidationResult TelemetryValidator::validate(
    const TelemetryFrame& frame) const {
    ValidationResult result{};

    // Collect all impossible values instead of stopping at the first one.
    if (frame.timestampSeconds < 0.0) {
        result.issues.push_back({
            "timestampSeconds",
            frame.timestampSeconds,
            "must not be negative"
        });
    }

    if (frame.enginePowerPercent < 0.0 ||
        frame.enginePowerPercent > 100.0) {
        result.issues.push_back({
            "enginePowerPercent",
            frame.enginePowerPercent,
            "must be between 0 and 100"
        });
    }

    if (frame.batteryPowerPercent < 0.0 ||
        frame.batteryPowerPercent > 100.0) {
        result.issues.push_back({
            "batteryPowerPercent",
            frame.batteryPowerPercent,
            "must be between 0 and 100"
        });
    }

    if (frame.speedMetersPerSecond < 0.0) {
        result.issues.push_back({
            "speedMetersPerSecond",
            frame.speedMetersPerSecond,
            "must not be negative"
        });
    }

    if (frame.altitudeMeters < 0.0) {
        result.issues.push_back({
            "altitudeMeters",
            frame.altitudeMeters,
            "must not be negative"
        });
    }

    return result;
}
