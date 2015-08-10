#include "Task.h"
#include "List.h"

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

List readyQueue;

Tcb *runningTcb;
Tcb mainTcb;
Tcb taskOneTcb;
Tcb taskTwoTcb;

void taskOne(void)
{
	//run one time only, use to identified task switch is correct
	asm(
		"ldr  r0, =#0xbabababa\n\t"
	);
    while(1);
}

void taskTwo(void)
{
	//run one time only, use to identified task switch is correct
	asm(
		"ldr  r0, =#0xabababab\n\t"
	);
    while(1);
}

/**
 * Initialize all the TCBs
 */
void initTcb()
{
	CpuContext *cc1, *cc2;

	listInit(&readyQueue);

    mainTcb.name = "main_thread";
    mainTcb.sp = 0;

    taskOneTcb.name = "thread #1";
    taskOneTcb.sp = (uint32_t)&taskOneStack[1028];
    cc1 = (CpuContext *)((uint32_t)&taskOneStack[1024] - sizeof(CpuContext));
	taskOneTcb.sp = (uint32_t)cc1;
	cc1->R0 = 0x10000001;
	cc1->R1 = 0x20000002;
	cc1->R2 = 0x30000003;
	cc1->R3 = 0x40000004;
	cc1->R4 = 0x50000005;
	cc1->R5 = 0x60000006;
	cc1->R6 = 0x70000007;
	cc1->R7 = 0x80000008;
	cc1->R8 = 0x90000009;
	cc1->R9 = 0xa000000a;
	cc1->R10 = 0xb000000b;
	cc1->R11 = 0xc000000c;
	cc1->R12 = 0xd000000d;
	cc1->LR = 0xe000000e;
	cc1->PC = (uint32_t *)taskOne;
	cc1->xPSR = 0x01000000;

	taskTwoTcb.name = "thread #2";
	taskTwoTcb.sp = (uint32_t)&taskTwoStack[1028];
	cc2 = (CpuContext *)((uint32_t)&taskTwoStack[1024] - sizeof(CpuContext));
	taskTwoTcb.sp = (uint32_t)cc2;
	cc2->R0 = 0xe000000e;
	cc2->R1 = 0xd000000d;
	cc2->R2 = 0xc000000c;
	cc2->R3 = 0xb000000b;
	cc2->R4 = 0xa000000a;
	cc2->R5 = 0x90000009;
	cc2->R6 = 0x80000008;
	cc2->R7 = 0x70000007;
	cc2->R8 = 0x60000006;
	cc2->R9 = 0x50000005;
	cc2->R10 = 0x40000004;
	cc2->R11 = 0x30000003;
	cc2->R12 = 0x20000002;
	cc2->LR = 0x10000001;
	cc2->PC = (uint32_t *)taskTwo;
	cc2->xPSR = 0x01000000;

	runningTcb = &mainTcb;

}
