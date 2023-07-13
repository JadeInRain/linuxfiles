
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

		/* if (!greatest_ticks) { */
		/* 	for (p = proc_table; p < proc_table+NR_TASKS; p++) { */
		/* 		p->ticks = p->priority; */
		/* 	} */
		/* } */
	}
	//display_process_counts();
}
/*PUBLIC void display_process_counts()
{
    disp_str("Process execution counts:\n");

    for (int i = 0; i < NR_TASKS; i++) {
        disp_str("Process ");
        disp_str(proc_table[i].p_name);
        disp_str(": ");
        disp_int(proc_table[i].num);
        disp_str("\n");
    }
}*/
/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	return ticks;
}

