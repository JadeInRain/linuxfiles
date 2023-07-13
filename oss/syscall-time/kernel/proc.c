
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
#include "stddef.h"

/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	disp_str("+");
/*	struct timeval tv;
    	struct tm* ptm;
    	char time_string[40];

    	// 获取当前时间
    	gettimeofday(&tv, null);
    
    	// 格式化时间
    	ptm = localtime(&tv.tv_sec);
    	strftime(time_string, sizeof(time_string), "%y-%m-%d %h:%m:%s", ptm);
    
    // 输出时间到屏幕
    	disp_str(time_string);
	return 0;
*/
}

