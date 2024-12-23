//
// Created by benjamin on 12/18/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "unity.h"
#include "../shared/search_next_schedule.h"


//// Configuración inicial antes de cada prueba
//void setUp(void) {}
//
//// Configuración final después de cada prueba
//void tearDown(void) {}

struct Device *mockDevice() {
    struct Device *device = (struct Device *)malloc(sizeof(struct Device));

    // Initialize Device fields
    device->code = "Device01";
    device->sizeSchedules = 7;  // Now we have 7 schedules
    device->sizeActuatorCodes = 1;
    device->dayNow = 3; // Let's assume it's Wednesday (3)

    // Allocate and initialize ActuatorCodes
    device->actuatorCodes = (struct ActuatorCodes **)malloc(sizeof(struct ActuatorCodes *));
    device->actuatorCodes[0] = (struct ActuatorCodes *)malloc(sizeof(struct ActuatorCodes));
    device->actuatorCodes[0]->code = "ACT001";

    // Allocate and initialize Schedules for 7 schedules
    device->schedules = (struct Schedule **)malloc(device->sizeSchedules * sizeof(struct Schedule *));

    for (int i = 0; i < device->sizeSchedules; i++) {
        device->schedules[i] = (struct Schedule *)malloc(sizeof(struct Schedule));

        // Initialize Schedule fields
        device->schedules[i]->dayMonday = false;
        device->schedules[i]->dayTuesday = false;
        device->schedules[i]->dayWednesday = false;
        device->schedules[i]->dayThursday = false;
        device->schedules[i]->dayFriday = false;
        device->schedules[i]->daySaturday = false;
        device->schedules[i]->daySunday = false;
        device->schedules[i]->sizeSequences = 1;

        // Allocate and initialize Sequences for each schedule
        device->schedules[i]->sequences = (struct Sequence **)malloc(device->schedules[i]->sizeSequences * sizeof(struct Sequence *));
        device->schedules[i]->sequences[0] = (struct Sequence *)malloc(sizeof(struct Sequence));

        // Initialize Sequence fields
        device->schedules[i]->sequences[0]->cycles = 3;
        device->schedules[i]->sequences[0]->start = 10;
        device->schedules[i]->sequences[0]->end = 50;
        device->schedules[i]->sequences[0]->sizeActuators = 1;
        device->schedules[i]->sequences[0]->offset = 5;

        // Allocate and initialize Actuators for each sequence
        device->schedules[i]->sequences[0]->actuators = (struct Actuator **)malloc(device->schedules[i]->sequences[0]->sizeActuators * sizeof(struct Actuator *));
        device->schedules[i]->sequences[0]->actuators[0] = (struct Actuator *)malloc(sizeof(struct Actuator));

        // Initialize Actuator fields
        device->schedules[i]->sequences[0]->actuators[0]->mcp23xxx = 0x20;
        device->schedules[i]->sequences[0]->actuators[0]->number = 1;
        device->schedules[i]->sequences[0]->actuators[0]->sizePatterns = 1;

        // Allocate and initialize Patterns for the Actuator
        device->schedules[i]->sequences[0]->actuators[0]->patterns = (struct Pattern **)malloc(device->schedules[i]->sequences[0]->actuators[0]->sizePatterns * sizeof(struct Pattern *));
        device->schedules[i]->sequences[0]->actuators[0]->patterns[0] = (struct Pattern *)malloc(sizeof(struct Pattern));

        // Initialize Pattern fields
        device->schedules[i]->sequences[0]->actuators[0]->patterns[0]->duration = 100;
        device->schedules[i]->sequences[0]->actuators[0]->patterns[0]->state = true;
    }

    return device;
}

struct tm mockTm() {
    struct tm mockedTime;

    mockedTime.tm_sec = 30;      // 30 seconds
    mockedTime.tm_min = 15;      // 15 minutes
    mockedTime.tm_hour = 10;     // 10:00 AM
    mockedTime.tm_mday = 25;     // 25th day of the month
    mockedTime.tm_mon = 11;      // December (months are 0-based)
    mockedTime.tm_year = 124;    // Year 2024 (since tm_year is years since 1900)
    mockedTime.tm_wday = 3;      // Wednesday (0=Sunday, 1=Monday, ..., 6=Saturday)
    mockedTime.tm_yday = 358;    // 358th day of the year (December 25th)
    mockedTime.tm_isdst = 0;     // No daylight saving time (0 = false)

    return mockedTime;
}



//Unit tests

//void test_dif(){
//    TEST_ASSERT_EQUAL(-1, dif(2, 3));
//    TEST_ASSERT_EQUAL(-3, dif(-2, 1));
//}

void test_searchNextSchedule_monday(){
    struct Device *deviceMocked = mockDevice();
    struct tm timeMocked = mockTm();
    timeMocked.tm_wday = 1;
    deviceMocked->schedules[0]->dayMonday = true;
    TEST_ASSERT_EQUAL(deviceMocked->schedules[0], searchNextSchedule(deviceMocked, timeMocked));
};


int ymain(){
    UNITY_BEGIN();
//    RUN_TEST(test_sum);
    RUN_TEST(test_searchNextSchedule_monday);
    return UNITY_END();
    return 0;
}