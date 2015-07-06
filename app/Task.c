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
	cc->R5 = 0x60000006;
	cc->R6 = 0x70000007;
	cc->R7 = 0x80000008;
	cc->R8 = 0x90000009;
	cc->R9 = 0xa000000a;
	cc->R10 = 0xb000000b;
	cc->R11 = 0xc000000c;
	cc->R12 = 0xd000000d;
	cc->LR = 0xe000000e;
	cc->PC = (uint32_t *)&taskOne;
	cc->xPSR = 0x01000000;
}
