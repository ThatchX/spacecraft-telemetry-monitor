# V1 test plan

No automated test framework is configured yet. The cases below were verified
manually by changing the sample frame in `src/main.cpp` and running the project
with **Command-Shift-B**. They define the initial automated-test backlog.

## Validation

- A nominal frame produces no validation issues and proceeds to evaluation.
- Battery power at -5% produces an issue containing the field name, value, and
  valid percentage range.
- A timestamp of -1 second and speed of -50 m/s produce two issues in one pass.
- An invalid frame exits with status 1 and does not produce a health report.
- Engine and battery percentages outside 0-100, negative timestamps, negative
  speeds, and negative altitudes should each be covered by automated tests.

## Health evaluation

| Subsystem | Nominal case | Warning case | Critical case |
| --- | --- | --- | --- |
| Electrical | Battery 88% | Battery 25% | Battery 10% |
| Propulsion | Engine power 72% | Engine power 90% | Engine power 95% |
| Attitude | Maximum deviation 1.2 degrees | Y deviation -5 degrees | Y deviation -15 degrees |
| Navigation | Speed 1800 m/s, altitude 42000 m | Speed 2500 m/s or altitude 20000 m | Speed 3000 m/s or altitude 10000 m |

Critical conditions are checked before warning conditions. Attitude tests include
negative values to verify that evaluation uses absolute deviation. Navigation
tests vary speed and altitude separately so the source of each status is clear.

## Reporting

- The report contains attitude, propulsion, navigation, and electrical statuses.
- Statuses are rendered as `NOMINAL`, `WARNING`, or `CRITICAL`.
- `ReportGenerator` formats an existing `HealthResult` without evaluating telemetry.
- Console output occurs in `main`, outside the evaluator and report generator.

## Future coverage

- Add automated cases immediately below, exactly at, and immediately above every
  threshold.
- Add focused unit tests for validation, evaluation, and report formatting.
- V2 tests will cover multiple independent timestamped frames and trend analysis.
