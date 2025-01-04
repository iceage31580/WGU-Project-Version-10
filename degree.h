#ifndef DEGREE_H
#define DEGREE_H

#include <string>

enum class Degree { Security, Network, Software };

inline std::string degreeToString(Degree degree) {
    switch (degree) {
    case Degree::Security: return "Security";
    case Degree::Network: return "Network";
    case Degree::Software: return "Software";
    default: return "Unknown";
    }
}

#endif
