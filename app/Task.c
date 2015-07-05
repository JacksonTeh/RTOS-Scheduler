#include "Task.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;

void taskOne(void)
{
    return;
}

/**
 * Initialize all the TCBs
 */
void initTcb()
{
	CpuContext *cc;

    mainTcb.name = "main_thread";
    mainTcb.sp = 0;

    taskOneTcb.name = "thread #1";
    taskOneTcb.sp = (uint32_t)&taskOneStack[1028];
	cc = (CpuContext *)((uint32_t)&taskOneStack[1024] - sizeof(CpuContext));
	taskOneTcb.sp = (uint32_t)cc;
	cc->R0 = 0x10000001;
	cc->R1 = 0x20000002;
	cc->R2 = 0x30000003;
	cc->R3 = 0x40000004;
	cc->R4 = 0x50000005;

}
