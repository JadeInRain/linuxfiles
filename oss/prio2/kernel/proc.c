
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
                              schedule
 *======================================================================*/
PUBLIC void schedule()
{
	PROCESS* p;
	int	 greatest_ticks = 0;

	while (!greatest_ticks) {
		for (p = proc_table; p < proc_table+NR_TASKS; p++) {
			if (p->ticks > greatest_ticks) {
				disp_str("<");
				disp_int(p->ticks);
				disp_str(">");
				greatest_ticks = p->ticks;
				p_proc_ready = p;
			}
		}
		}
	/*if (!greatest_ticks) {
            // 检查所有进程的ticks是否都为零
            int all_ticks_zero = 1;
            for (p = proc_table; p < proc_table+NR_TASKS; p++) {
                if (p->ticks > 0) {
                    all_ticks_zero = 0;
                    break;
                }
            }
		disp_str("!!!!!!!!!");
            // 如果所有进程的ticks都为零，显示执行次数并重置进程优先级
            if (all_ticks_zero) {
                display_process_counts();
            }
		/* if (!greatest_ticks) { */
		/* 	for (p = proc_table; p < proc_table+NR_TASKS; p++) { */
		/* 		p->ticks = p->priority; */
		/* 	} */
		/* } */
	//}
	if (!greatest_ticks) {
	for (p = proc_table; p < proc_table+NR_TASKS; p++) { 
	p->ticks = p->priority;
	} 
	}
	
	
}

/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	return ticks;
}
PUBLIC void display_process_counts()
{
    disp_str("Process execution counts:\n");

    for (int i = 0; i < NR_TASKS; i++) {
        disp_str("Process ");
        disp_str(proc_table[i].p_name);
        disp_str(": ");
        disp_int(proc_table[i].num);
        disp_str("\n");
    }
}
