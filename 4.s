mov r1,#21
and r2,r1,#1
cmp r2,#0
beq L1
mov r0,#0xff
L1: mov r0,#0x00

