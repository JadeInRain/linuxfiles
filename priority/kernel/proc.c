
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
	int greatest_ticks = 0;
	int bw=0;
	int cw=0;
	while (!greatest_ticks) {
		for (p = proc_table; p < proc_table+NR_TASKS; p++) {
			if (p->ticks > greatest_ticks) {
				disp_str("<");
				disp_int(p->ticks);
				disp_str(">");
				greatest_ticks = p->ticks;
				p_proc_ready = p;
				if (p->has_started == 0) {
                    			p->arrival_time = sys_get_ticks();
                    			p->has_started = 1;
                		}
			}
		}
		if (!greatest_ticks) {
            // check if all ticks turn to 0
            		int all_ticks_zero = 1;
            		for (p = proc_table; p < proc_table+NR_TASKS; p++) {
                		if (p->ticks > 0) {
                    			all_ticks_zero = 0;
                    			break;
                		}
            		}

            // if ticks of all progress turn to 0, set completion_time, cal waiting_time, display
			if (all_ticks_zero) {
				for (p = proc_table; p < proc_table+NR_TASKS; p++) {
		    			p->completion_time = sys_get_ticks(); 
		    			p->waiting_time = p->completion_time-p->arrival_time-p->num;
				}
			    display_process_counts(); 
			}
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
    	disp_str("Process execution counts, turnaround times, and waiting times:\n");
	int total_waiting_time=0;
	int total_turnaround_time=0;
    	for (int i = 0; i < NR_TASKS; i++) {
        disp_str("Process ");
        disp_str(proc_table[i].p_name);
        disp_str(": ");
        disp_int(proc_table[i].num);
        disp_str("\n");

	int arrival_time = (proc_table[i].arrival_time);
        disp_str("Arrival time for ");
        disp_str(proc_table[i].p_name);
        disp_str(": ");
        disp_int(arrival_time);
        disp_str(" ms\n");
        
        int turnaround_time = (proc_table[i].completion_time-proc_table[i].arrival_time);
        total_turnaround_time += turnaround_time;
        disp_str("Turnaround time for ");
        disp_str(proc_table[i].p_name);
        disp_str(": ");
        disp_int(turnaround_time);
        disp_str(" ms\n");

        int waiting_time = proc_table[i].waiting_time ;
        total_waiting_time += waiting_time;
        disp_str("Waiting time for ");
        disp_str(proc_table[i].p_name);
        disp_str(": ");
        disp_int(waiting_time);
        disp_str(" ms\n");
    }

    int average_turnaround_time = total_turnaround_time / NR_TASKS;
    int average_waiting_time = total_waiting_time / NR_TASKS;
    int throughput = NR_TASKS * 1000 / (proc_table[NR_TASKS - 1].completion_time); 

    disp_str("\nAverage turnaround time: ");
    disp_int(average_turnaround_time);
    disp_str(" ms\n");

    disp_str("Average waiting time: ");
    disp_int(average_waiting_time);
    disp_str(" ms\n");

    disp_str("Throughput: ");
    disp_int(throughput);
    disp_str(" processes per second\n");
    while(1){}
}
