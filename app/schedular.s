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
  push	{r0}
  b		.

  .align 8
  .type SysTick_Handler, %function
SysTick_Handler:
  //code here...put the rest of the register
  stmdb SP!, {r4-r11}
  ldr	r0, =mainTcb
  ldr	r1, =#0x0
  add	r1, sp
  str	r1, [r0, #TCB_SP]
  ldr	r0, =taskOneTcb
  ldr	sp, [r0, #TCB_SP]
  bx	lr
  //push	{r7, lr}
  //add 	r7, sp, #0
  //bl	HAL_IncTick
  //pop	{r7, pc}
