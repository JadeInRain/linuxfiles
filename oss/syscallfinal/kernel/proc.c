#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "sys/time.h"
#include "stdio.h"
#include "unistd.h"
#include "rtc.h"
/*======================================================================*
                           sys_get_times
 *======================================================================*/
 #include <stdint.h>

void stoc(uint32_t value, char *str, uint32_t base)
{
    char *p = str;
    char *p1, *p2;
    uint32_t tmp;

    if (value == 0)
    {
        *str++ = '0';
        *str = '\0';
        return;
    }

    while (value > 0)
    {
        tmp = value / base;
        *p++ = "0123456789ABCDEF"[value - (tmp * base)];
        value = tmp;
    }

    *p-- = '\0';

    p1 = str;
    p2 = p;
    while (p1 < p2)
    {
        char tmp_char = *p1;
        *p1 = *p2;
        *p2 = tmp_char;
        p1++;
        p2--;
    }
}
#include "proto.h"
#include "rtc.h"

void print_rtc_time()
{
    RTC_TIME t = get_rtc_time();
    char str[12];

    disp_str("Year: ");
    stoc(t.year, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Month: ");
    stoc(t.month, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Day: ");
    stoc(t.day, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Hour: ");
    stoc(t.hour, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Minute: ");
    stoc(t.minute, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Second: ");
    stoc(t.second, str, 10);
    disp_str(str);
    disp_str("\n");
    //second
    
    stoc(t.year, str, 10);
    disp_str(str);
    disp_str("-");

    stoc(t.month, str, 10);
    disp_str(str);
    disp_str("-");

    stoc(t.day, str, 10);
    disp_str(str);
    disp_str(" ");

    stoc(t.hour, str, 10);
    disp_str(str);
    disp_str(":");

    stoc(t.minute, str, 10);
    disp_str(str);
    disp_str(":");

    stoc(t.second, str, 10);
    disp_str(str);
    disp_str("\n");
    
    //third
    stoc(t.day, str, 10);
    disp_str(str);
    disp_str("/");
    
    stoc(t.month, str, 10);
    disp_str(str);
    disp_str("/");
    
    stoc(t.year, str, 10);
    disp_str(str);

}
PUBLIC int sys_get_ticks()
{
	print_rtc_time();
	return 0;
}
