# Spacecraft Telemetry Monitor

A C++ technical-screen practice project that validates one spacecraft telemetry
frame, evaluates subsystem health, and prints a structured operator report.

## V1 scope

Process one telemetry frame with these fields:

- Timestamp
- X, Y, and Z attitude axes
- Engine power (%)
- Speed
- Altitude
- Battery/electrical power (%)

All telemetry fields use `double`. Timestamps are seconds from the start of the
monitoring session, attitude values are deviations in degrees, speed is meters
per second, altitude is meters, and power values are percentages.

Pipeline:

```text
TelemetryFrame -> validation -> HealthEvaluator -> HealthResult -> ReportGenerator
```

Keep data, validation, evaluation, and reporting separate. Invalid or impossible
readings are distinct from valid but dangerous readings: battery at -5% is invalid
telemetry; battery at 5% is valid telemetry that may indicate a critical condition.
Validation should identify the offending field and value, and invalid frames
should not proceed to health evaluation. `TelemetryValidator` returns a
`ValidationResult` containing every `ValidationIssue` found in the frame.

`HealthResult` contains attitude, propulsion, navigation, and electrical
subsystem statuses using `NOMINAL`, `WARNING`, and `CRITICAL`.
Health evaluation returns structured results; `ReportGenerator` formats them,
and `main` handles console output.

Named `constexpr` thresholds in `include/Thresholds.h` define these V1 boundaries:

- Electrical: battery at or below 15% is critical; at or below 30% is warning.
- Propulsion: engine power at or above 95% is critical; at or above 85% is warning.
- Attitude: an absolute deviation of at least 15 degrees on any axis is critical;
  at least 5 degrees is warning.
- Navigation: speed at or above 3000 m/s or altitude at or below 10000 m is
  critical; speed at or above 2500 m/s or altitude at or below 20000 m is warning.

Critical conditions are evaluated before warning conditions at overlapping
boundaries.

## File responsibilities

- `include/TelemetryFrame.h`: telemetry data definition.
- `include/HealthResult.h`: status enum and structured subsystem results.
- `include/TelemetryValidator.h`, `src/TelemetryValidator.cpp`: input validation.
- `include/HealthEvaluator.h`, `src/HealthEvaluator.cpp`: subsystem evaluation.
- `include/ReportGenerator.h`, `src/ReportGenerator.cpp`: report formatting.
- `include/Thresholds.h`: named compile-time thresholds.
- `src/main.cpp`: constructs a sample frame and runs the complete V1 pipeline.
- `tests/README.md`: testing checklist and boundary cases.
- `.vscode/tasks.json`, `.vscode/launch.json`: build and debug configuration.

## Build and debug

Open this `spacecraft-telemetry-monitor` folder as the VS Code workspace root.
The supplied configuration targets macOS/Linux with `clang++` on PATH and uses
C++17. On macOS, install the Xcode Command Line Tools if needed. Breakpoint
debugging uses the LLVM LLDB DAP extension (`llvm-vs-code-extensions.lldb-dap`).

Press **Command-Shift-B** to compile the four source files and run
`build/spacecraft-telemetry-monitor` in the integrated terminal. Press **F5** and
select **Run telemetry monitor in terminal** for the same terminal-based output.
Select **Debug telemetry monitor** when breakpoint debugging is needed.

## Project history

See [`CHANGELOG.md`](CHANGELOG.md) for dated implementation milestones.

## Planned V2

Process multiple independent timestamped frames and add trend analysis across
frames. V1 remains focused on a single frame; V2 behavior is not implemented here.
