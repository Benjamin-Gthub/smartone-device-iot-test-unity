//
// Created by benjamin on 12/18/2024.
//
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "storage.h"
#include "search_next_schedule.h"


struct Schedule *searchNextSchedule(struct Device *device, struct tm date) {
    device->dayNow = date.tm_wday;

//    ESP_LOGI(TAG, "Device size schedules %d", device->sizeSchedules);

    for (int iSchedule = 0; iSchedule < device->sizeSchedules; iSchedule++) {
        struct Schedule *schedule = device->schedules[iSchedule];
        if (schedule->daySunday == true && device->dayNow == 0) {
            return schedule;
        }
        if (schedule->dayMonday == true && device->dayNow == 1) {
            return schedule;
        }
        if (schedule->dayTuesday == true && device->dayNow == 2) {
            return schedule;
        }
        if (schedule->dayWednesday == true && device->dayNow == 3) {
            return schedule;
        }
        if (schedule->dayThursday == true && device->dayNow == 4) {
            return schedule;
        }
        if (schedule->dayFriday == true && device->dayNow == 5) {
            return schedule;
        }
        if (schedule->daySaturday == true && device->dayNow == 6) {
            return schedule;
        }
    }
    return NULL;
}