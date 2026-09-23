#pragma once

struct TelemetryFrame {
    // Time elapsed since the monitoring session began.
    double timestampSeconds{};

    // Deviation from the commanded attitude on each axis.
    double attitudeXDegrees{};
    double attitudeYDegrees{};
    double attitudeZDegrees{};

    // Propulsion output and spacecraft speed.
    double enginePowerPercent{};
    double speedMetersPerSecond{};

    // Position and remaining electrical power.
    double altitudeMeters{};
    double batteryPowerPercent{};
};
