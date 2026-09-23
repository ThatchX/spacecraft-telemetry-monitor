# Spacecraft Telemetry Monitor

Will's DeepSpace C++ technical-screen practice project. This is a skeleton;
Will implements the validation, health evaluation, and reporting logic.

## V1 scope

Process one telemetry frame with these fields:

- Timestamp
- X, Y, and Z attitude axes
- Engine power (%)
- Speed
- Altitude
- Battery/electrical power (%)

TODO: Choose field types, units, and the timestamp convention before implementation.

Pipeline:

```text
TelemetryFrame -> validation -> HealthEvaluator -> HealthResult -> ReportGenerator
```

Keep data, validation, evaluation, and reporting separate. Invalid or impossible
readings are distinct from valid but dangerous readings: battery at -5% is invalid
telemetry; battery at 5% is valid telemetry that may indicate a critical condition.
Validation should identify the offending field and value, and invalid frames
should not proceed to health evaluation. The validator's boolean declaration is
a starting point; TODO: design validation diagnostics before implementing it.

`HealthResult` will contain individual subsystem statuses using `NOMINAL`,
`WARNING`, and `CRITICAL`. TODO: Decide subsystem groupings and result members.
Health evaluation returns structured results; `ReportGenerator` formats them,
and `main` will handle console output.

Define named `constexpr` thresholds in `include/Thresholds.h`. Choose and document
their values, units, and boundary behavior as part of the exercise; do not scatter
numeric thresholds throughout the implementation.

## File responsibilities

- `include/TelemetryFrame.h`: telemetry data definition.
- `include/HealthResult.h`: status enum and structured subsystem results.
- `include/TelemetryValidator.h`, `src/TelemetryValidator.cpp`: input validation.
- `include/HealthEvaluator.h`, `src/HealthEvaluator.cpp`: subsystem evaluation.
- `include/ReportGenerator.h`, `src/ReportGenerator.cpp`: report formatting.
- `include/Thresholds.h`: named compile-time thresholds.
- `src/main.cpp`: future pipeline wiring; currently returns successfully.
- `tests/README.md`: testing checklist for later implementation.
- `.vscode/tasks.json`, `.vscode/launch.json`: build and debug configuration.

## Build and debug

Open this `spacecraft-telemetry-monitor` folder as the VS Code workspace root.
The supplied configuration targets macOS/Linux with `clang++` on PATH and uses
C++17. On macOS, install the Xcode Command Line Tools if needed. Install the
VS Code CodeLLDB extension (`vadimcn.vscode-lldb`) for debugging.

Run **Terminal -> Run Build Task** to compile the four source files into
`build/spacecraft-telemetry-monitor`. Press **F5** and select **Debug telemetry
monitor** to build and launch it. The skeleton produces no console output.

The interface methods are declared but intentionally not defined. Implement them
before calling them from `main`, or the linker will report missing definitions.

## Planned V2

Process multiple independent timestamped frames and add trend analysis across
frames. V1 remains focused on a single frame; V2 behavior is not implemented here.
