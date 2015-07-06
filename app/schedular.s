  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global	taskSwitch
.global	SysTick_Handler
.extern mainTcb
.extern taskOneTcb
.extern taskTwoTcb

.equ TCB_NEXT,	0
.equ TCB_NAME,	4
.equ TCB_SP,	8

  .section  .text.taskSwitch
  .type  taskSwitch, %function
taskSwitch:
  push	{lr}
  ldr	r0, =#0x11111111
  ldr	r1, =#0x22222222
  ldr	r2, =#0x33333333
  ldr	r3, =#0x44444444
  ldr	r4, =#0x55555555
  ldr	r5, =#0x66666666
  ldr	r6, =#0x77777777
  ldr	r7, =#0x88888888
  ldr	r8, =#0x99999999
  ldr	r9, =#0xaaaaaaaa
  ldr	r10, =#0xbbbbbbbb
  ldr	r11, =#0xcccccccc
  ldr	r12, =#0xabababab
  ldr	lr, =#0xcdcdcdcd
  //push	{r0}
  b		.

/****************************************************************
// 1) push all neccesary registers
// 2) load mainTcb
// 3) store sp into mainTcb.sp
// 4) load taskOneTcb
// 5) load taskOneTcb.sp into sp
// 6) pop all push registers
// 7) return from interrupt

// 1) push all neccesary registers
// 2) load runningTcb
// 3) store sp into runningTcb.sp
//	  a) push lr
// 4) r5 = listRemoveHead() => return to r0, ldr again to r5
// 5) load r5.sp into sp
// 6) let runningTcb = r5
// 7) listAddTail(r4) => return to r0, ldr again to r4
//    a) pop lr
// 8) pop all push registers
// 9) return from interrupt
****************************************************************/
  .align 8
  .type SysTick_Handler, %function
SysTick_Handler:
  //code here...push the rest of the register

  push	{r4-r11}
  //pop	{r4-r11, r0-r3}
  //pop	{r12, r0-r2}
  //pop	{r3}				//pop the link reg value to return to caller
  ldr	r0, =mainTcb
  ldr	r1, =#0x0
  add	r1, sp
  str	r1, [r0, #TCB_SP]
  ldr	r0, =taskOneTcb
  ldr	sp, [r0, #TCB_SP]
  pop	{r4-r11}
  //ldr	lr, =#0x0
  //add	lr, r3
  bx	lr

  //push	{r7, lr}
  //add 	r7, sp, #0
  //bl	HAL_IncTick
  //pop	{r7, pc}
