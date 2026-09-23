#pragma once

namespace Thresholds {
    // Electrical power: lower values indicate greater risk.
    inline constexpr double batteryCriticalPercent = 15.0;
    inline constexpr double batteryWarningPercent = 30.0;

    // Propulsion output: higher values indicate greater risk.
    inline constexpr double enginePowerCriticalPercent = 95.0;
    inline constexpr double enginePowerWarningPercent = 85.0;

    // Attitude uses the absolute deviation on any axis.
    inline constexpr double attitudeCriticalDegrees = 15.0;
    inline constexpr double attitudeWarningDegrees = 5.0;

    // Navigation treats excessive speed as dangerous.
    inline constexpr double speedCriticalMetersPerSecond = 3000.0;
    inline constexpr double speedWarningMetersPerSecond = 2500.0;

    // Navigation also treats low altitude as dangerous.
    inline constexpr double altitudeCriticalMeters = 10000.0;
    inline constexpr double altitudeWarningMeters = 20000.0;
}
