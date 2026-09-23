#pragma once

enum class HealthStatus {
    NOMINAL,
    WARNING,
    CRITICAL
};

// Each subsystem starts nominal and is promoted when a threshold is reached.
struct HealthResult {
    HealthStatus attitudeStatus{HealthStatus::NOMINAL};
    HealthStatus propulsionStatus{HealthStatus::NOMINAL};
    HealthStatus navigationStatus{HealthStatus::NOMINAL};
    HealthStatus electricalStatus{HealthStatus::NOMINAL};
};
