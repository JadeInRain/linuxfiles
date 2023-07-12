#include "const.h"
#include "type.h"
#include "protect.h"
#include "proc.h"
#include "rtc.h"

#define CMOS_ADDRESS 0x70
#define CMOS_DATA    0x71

PRIVATE u8 get_rtc_register(int reg) {
    out_byte(CMOS_ADDRESS, reg);
    return in_byte(CMOS_DATA);
}

PUBLIC RTC_TIME get_rtc_time() {
    RTC_TIME time;

    time.second = get_rtc_register(0x00);
    time.minute = get_rtc_register(0x02);
    time.hour   = get_rtc_register(0x04);
    time.day    = get_rtc_register(0x07);
    time.month  = get_rtc_register(0x08);
    time.year   = get_rtc_register(0x09);

    u8 status_reg_b = get_rtc_register(0x0B);

    // Convert BCD to binary values if necessary
    if ((status_reg_b & 0x04) == 0) {
        time.second = (time.second & 0x0F) + ((time.second / 16) * 10);
        time.minute = (time.minute & 0x0F) + ((time.minute / 16) * 10);
        time.hour   = ((time.hour & 0x0F) + (((time.hour & 0x70) / 16) * 10)) | (time.hour & 0x80);
        time.day    = (time.day & 0x0F) + ((time.day / 16) * 10);
        time.month  = (time.month & 0x0F) + ((time.month / 16) * 10);
        time.year   = (time.year & 0x0F) + ((time.year / 16) * 10);
    }

    // Convert 12 hour clock to 24 hour clock if necessary
    if (!(status_reg_b & 0x02) && (time.hour & 0x80)) {
        time.hour = ((time.hour & 0x7F) + 12) % 24;
    }

    // Calculate the full (4-digit) year
    time.year += (CURRENT_YEAR / 100) * 100;
    if (time.year < CURRENT_YEAR) time.year += 100;

    return time;
}
