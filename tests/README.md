# Future tests

TODO: Choose a test framework and add tests as the implementation takes shape.

- Invalid/impossible values produce diagnostics identifying the field and value.
- Valid dangerous readings pass validation and receive an appropriate status.
- Each subsystem covers NOMINAL, WARNING, and CRITICAL conditions.
- Threshold boundaries are checked immediately below, at, and above each value.
- Reporting reflects structured results and does not change evaluation behavior.
- V2: Multiple timestamped frames remain independent and support trend analysis.

No test framework or health-monitoring tests are implemented in this skeleton.
