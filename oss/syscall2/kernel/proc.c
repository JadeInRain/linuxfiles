
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               proc.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

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
                           sys_get_ticks
 *======================================================================*/
 #include <stdint.h>

void itoaa(uint32_t value, char *str, uint32_t base)
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
    itoaa(t.year, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Month: ");
    itoaa(t.month, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Day: ");
    itoaa(t.day, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Hour: ");
    itoaa(t.hour, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Minute: ");
    itoaa(t.minute, str, 10);
    disp_str(str);
    disp_str(" ");

    disp_str("Second: ");
    itoaa(t.second, str, 10);
    disp_str(str);
    disp_str("\n");
    //second
    
    itoaa(t.year, str, 10);
    disp_str(str);
    disp_str("-");

    itoaa(t.month, str, 10);
    disp_str(str);
    disp_str("-");

    itoaa(t.day, str, 10);
    disp_str(str);
    disp_str(" ");

    itoaa(t.hour, str, 10);
    disp_str(str);
    disp_str(":");

    itoaa(t.minute, str, 10);
    disp_str(str);
    disp_str(":");

    itoaa(t.second, str, 10);
    disp_str(str);
    disp_str("\n");
}
PUBLIC int sys_get_ticks()
{
	//disp_str("+");
	//RTC_TIME t = get_rtc_time();
	//sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", t.year, t.month, t.day, t.hour, t.minute, t.second);
	//disp_str(t);
	//disp_str(t.year);
	//disp_str("i");
	print_rtc_time();
	return 0;
}
