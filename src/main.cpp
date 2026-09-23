#include "HealthEvaluator.h"
#include "ReportGenerator.h"
#include "TelemetryFrame.h"
#include "TelemetryValidator.h"

#include <iostream>

int main() {
    // Nominal sample used to exercise the complete V1 pipeline.
    TelemetryFrame frame{};

    frame.timestampSeconds = 12.5;
    frame.attitudeXDegrees = 1.2;
    frame.attitudeYDegrees = -0.4;
    frame.attitudeZDegrees = 0.1;

    frame.enginePowerPercent = 72.0;
    frame.speedMetersPerSecond = 1800.0;

    frame.altitudeMeters = 42000.0;
    frame.batteryPowerPercent = 88.0;

    const TelemetryValidator validator{};
    const ValidationResult validation = validator.validate(frame);

    // Invalid telemetry never proceeds to health evaluation.
    if (!validation.isValid()) {
        for (const ValidationIssue& issue : validation.issues) {
            std::cerr << "Invalid telemetry: "
                      << issue.fieldName << " = " << issue.value
                      << " (" << issue.message << ")\n";
        }
        return 1;
    }

    // Evaluate and report only after validation succeeds.
    const HealthEvaluator evaluator{};
    const HealthResult healthResult = evaluator.evaluate(frame);

    const ReportGenerator reportGenerator{};
    std::cout << reportGenerator.generate(healthResult);

    return 0;
}
