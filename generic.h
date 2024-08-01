#ifndef GENERIC_H
#define GENERIC_H

#include <ctime>
#include <string>
#include <vector>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

std::string formatTime(std::time_t timeSubmitted) {
    struct tm timeinfo;
#ifdef _MSC_VER
    localtime_s(&timeinfo, &timeSubmitted);
#else
    localtime_r(&timeSubmitted, &timeinfo);
#endif
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return std::string(buffer);
}

#endif
