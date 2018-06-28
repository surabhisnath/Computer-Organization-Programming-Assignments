.equ SWI_PrInt, 0x6b
.equ SWI_Exit, 0x11

mov r4, #0	@Stores the sum
mov r5, #1	@Counter for loop
mov r0, #0
swi 0x6c	@Take input
mov r6, r0	@r6 stores n


loop:
	cmp r5, r6		@Compare counter and n
	bgt loop_exit
	mov r0, #0		
	swi 0x6c		@Take input number to add
	mov r7, r0		@Store number in r7
	add r4, r4, r7		@add it to sum
	add r5, r5, #1		@Increment counter
b loop

loop_exit:

mov r0, #1
mov r1, r4
swi SWI_PrInt			@Print sum
swi SWI_Exit 



0x0 E3A04000
0x4 E3A05001
0x8 E3A00000
0xC EF00006C
0x10 E1A06000
0x14
0x14 E1550006 
0x18 CA000005
0x1C E3A00000
0x20 EF00006C
0x24 E1A07000
0x28 E0844007
0x2C E2855001
0x30 EAFFFFF7
0x34
0x34 E3A00001
0x38 E1A01004
0x3C EF00006B
0x40 EF000011
