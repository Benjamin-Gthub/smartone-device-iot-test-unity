#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "cJSON.h"
#include "time.h"

#define nullptr ((void *)0)

struct Pattern {
    uint16_t duration;
    bool state;
};

struct Actuator {
    uint8_t mcp23xxx;
    uint16_t number;
    uint16_t sizePatterns;
    struct Pattern **patterns;
};

struct Sequence {
    int cycles;
    int start;
    int end;
    struct Actuator **actuators;
    uint16_t sizeActuators;
    uint16_t offset;
};

struct Schedule {
    bool dayMonday;
    bool dayTuesday;
    bool dayWednesday;
    bool dayThursday;
    bool dayFriday;
    bool daySaturday;
    bool daySunday;
    int sizeSequences;
    struct Sequence **sequences;
};

struct ActuatorCodes {
    char *code;
};

struct Device {
    char *code;
    int sizeSchedules;
    struct Schedule **schedules;
    int sizeActuatorCodes;
    struct ActuatorCodes **actuatorCodes;
    int dayNow;
};
