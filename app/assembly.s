  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  testFunc
.extern  dummy

  .section  .text.testFunc
  .type  testFunc, %function
testFunc:
  movs	r0, #0x12
  movs	r1, #0x34
  movs	r2, #0x56
  ldr	r3, =#0x1234face	//use this if more than one byte
  movw.w	r4, 0xface
  movt.w	r4, 0x1234
  stmdb SP!, {r0,r1}
  push	{r1, r0, r2}
  pop	{R0}
  //stmdb sp! {r0, r1, r2}
  push  {lr}
  movs  r0,#12				//put value into dummy
  bl    dummy
  bx	lr					//branch exchange => go back to whr it call this func
