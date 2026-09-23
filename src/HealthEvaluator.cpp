#include "HealthEvaluator.h"
#include "Thresholds.h"

#include <cmath>

HealthResult HealthEvaluator::evaluate(
    const TelemetryFrame &frame) const
{
    HealthResult result{};

    // Critical checks come first because critical values also cross warning
    // thresholds.
    if (frame.batteryPowerPercent <=
        Thresholds::batteryCriticalPercent)
    {
        result.electricalStatus = HealthStatus::CRITICAL;
    }
    else if (frame.batteryPowerPercent <=
             Thresholds::batteryWarningPercent)
    {
        result.electricalStatus = HealthStatus::WARNING;
    }

    if (frame.enginePowerPercent >=
        Thresholds::enginePowerCriticalPercent)
    {
        result.propulsionStatus = HealthStatus::CRITICAL;
    }
    else if (frame.enginePowerPercent >=
             Thresholds::enginePowerWarningPercent)
    {
        result.propulsionStatus = HealthStatus::WARNING;
    }

    // Positive and negative rotations have the same deviation magnitude.
    const bool attitudeIsCritical =
        std::abs(frame.attitudeXDegrees) >=
            Thresholds::attitudeCriticalDegrees ||
        std::abs(frame.attitudeYDegrees) >=
            Thresholds::attitudeCriticalDegrees ||
        std::abs(frame.attitudeZDegrees) >=
            Thresholds::attitudeCriticalDegrees;

    const bool attitudeIsWarning =
        std::abs(frame.attitudeXDegrees) >=
            Thresholds::attitudeWarningDegrees ||
        std::abs(frame.attitudeYDegrees) >=
            Thresholds::attitudeWarningDegrees ||
        std::abs(frame.attitudeZDegrees) >=
            Thresholds::attitudeWarningDegrees;

    if (attitudeIsCritical)
    {
        result.attitudeStatus = HealthStatus::CRITICAL;
    }
    else if (attitudeIsWarning)
    {
        result.attitudeStatus = HealthStatus::WARNING;
    }

    // Either excessive speed or low altitude can raise navigation severity.
    const bool navigationIsCritical =
        frame.speedMetersPerSecond >=
            Thresholds::speedCriticalMetersPerSecond ||
        frame.altitudeMeters <=
            Thresholds::altitudeCriticalMeters;

    const bool navigationIsWarning =
        frame.speedMetersPerSecond >=
            Thresholds::speedWarningMetersPerSecond ||
        frame.altitudeMeters <=
            Thresholds::altitudeWarningMeters;

    if (navigationIsCritical)
    {
        result.navigationStatus = HealthStatus::CRITICAL;
    }
    else if (navigationIsWarning)
    {
        result.navigationStatus = HealthStatus::WARNING;
    }

    return result;
}
