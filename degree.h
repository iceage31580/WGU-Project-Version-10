#pragma once
#ifndef DEGREE_H
#define DEGREE_H
//Completes Requirement B
#include <string>


//Corrects Mistake D.2e from previous submission
//allows program names to be shown now
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
