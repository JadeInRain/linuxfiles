
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


/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	struct rtc_time {
        unsigned char second;
        unsigned char minute;
        unsigned char hour;
        unsigned char day;
        unsigned char month;
        unsigned int year;
    } *rtc;

    unsigned char *rtc_addr = (unsigned char *)0x00000700; // RTC CMOS RAM 地址

    rtc = (struct rtc_time *)rtc_addr;
	RTC_TIME t = get_rtc_time();
    // 获取当前时间
    unsigned char second = rtc->second;
    unsigned char minute = rtc->minute;
    unsigned char hour = rtc->hour;
    unsigned char day = rtc->day;
    unsigned char month = rtc->month;
    unsigned int year = rtc->year + 2000;

    // 格式化时间输出
    char time_str[20];
    //disp_str("+");
    //ksprintf(time_str, "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);

    // 输出时间
    disp_str(time_str);
	//disp_str(month -  - 1);
	//disp_char('a');

    return 0;
	
}

