#include "ReportGenerator.h"

#include <sstream>

namespace {

const char* statusToString(HealthStatus status) {
    switch (status) {
        case HealthStatus::NOMINAL:
            return "NOMINAL";
        case HealthStatus::WARNING:
            return "WARNING";
        case HealthStatus::CRITICAL:
            return "CRITICAL";
    }

    return "UNKNOWN";
}

}  // namespace

std::string ReportGenerator::generate(
    const HealthResult& result) const {
    std::ostringstream report;

    report << "Spacecraft Health Report\n"
           << "Attitude: "
           << statusToString(result.attitudeStatus) << '\n'
           << "Propulsion: "
           << statusToString(result.propulsionStatus) << '\n'
           << "Navigation: "
           << statusToString(result.navigationStatus) << '\n'
           << "Electrical: "
           << statusToString(result.electricalStatus) << '\n';

    return report.str();
}
