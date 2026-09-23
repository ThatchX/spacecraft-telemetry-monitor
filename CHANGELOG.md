# Changelog

This file records notable changes to the Spacecraft Telemetry Monitor.

## V1 - 2026-09-23

### Added

- A C++17 project structure with separate data, validation, evaluation, reporting,
  and application-entry responsibilities.
- A `TelemetryFrame` containing timestamp, X/Y/Z attitude deviation, engine power,
  speed, altitude, and battery power readings.
- Structured validation results that collect every impossible reading and identify
  its field, value, and validation rule.
- `NOMINAL`, `WARNING`, and `CRITICAL` statuses for attitude, propulsion,
  navigation, and electrical subsystems.
- Named `constexpr` thresholds for battery power, engine power, attitude
  deviation, speed, and altitude.
- A health evaluator that distinguishes valid dangerous readings from invalid
  telemetry.
- A report generator that converts structured health results into console output.
- VS Code tasks for building and running the complete project in the integrated
  terminal.
- Separate VS Code configurations for terminal runs and LLDB breakpoint debugging.
- A documented manual test plan covering validation and subsystem boundaries.

### Changed

- Replaced the original skeleton behavior with a complete single-frame V1
  pipeline:

  ```text
  TelemetryFrame -> validation -> HealthEvaluator -> HealthResult -> ReportGenerator
  ```

- Updated the project README with field units, subsystem thresholds, architecture,
  build instructions, and planned V2 scope.
- Added concise source comments and cleaned whitespace, spacing, and unused
  includes.

### Verified

- Confirmed nominal, warning, and critical behavior for every subsystem.
- Confirmed exact threshold boundaries for propulsion, attitude, speed, and
  altitude.
- Confirmed negative attitude values use absolute deviation.
- Confirmed multiple invalid fields are reported in one pass.
- Confirmed invalid frames exit with status 1 and do not produce a health report.
- Built successfully with `-Wall`, `-Wextra`, and `-Wpedantic` and no warnings.

## Planned V2

- Process multiple independent timestamped telemetry frames.
- Add trend analysis across frames.
