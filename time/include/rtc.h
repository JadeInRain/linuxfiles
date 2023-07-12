#ifndef _RTC_H
#define _RTC_H

#include "type.h"

typedef struct {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
} RTC_TIME;

PUBLIC RTC_TIME get_rtc_time();

#endif /* _RTC_H */
