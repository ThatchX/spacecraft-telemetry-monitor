#pragma once

enum class HealthStatus {
    NOMINAL,
    WARNING,
    CRITICAL
};

struct HealthResult {
    // TODO: Add individual subsystem HealthStatus members.
    // TODO: Decide which diagnostic details belong in the structured result.
};
