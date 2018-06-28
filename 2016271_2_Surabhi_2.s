.equ SWI_PrInt, 0x6b
.equ SWI_Exit, 0x11

mov r4, #0		@First value in fibonacci series is 0
mov r5, #1		@Second value in fibonacci series is 1

mov r0, #0 
swi 0x6c		@Take input

mov r6, r0		@r6 stores n
subs r6,r6,#1		




mov r7,#1
@mov r7, #2		@Counter for loop 
loop:
	cmp r7, r6	@Compare n and counter
	bgt loop_exit 
	add r8,r5,r4	@Find the next fibonacci number
	mov r4,r5
	mov r5, r8
	add r7,r7,#1	@Increment the counter
b loop			@r8 stores the nth fibonacci number

loop_exit:
mov r9, #0 		@Stores reverse
mov r8, r4
change:
	mov r12, r8	@Store r8 in a register
	cmp r8, #1	
	blt change_exit

	mov r10, #0	@Counter for subtract
	subtract:
		cmp r8, #10	
		blt subtract_exit
		subs r8, r8, #10	@Stores mod
		add r10, r10, #1	@Stores quotient
	b subtract

	subtract_exit:
	mov r11, #10
	mul r9, r11, r9			@Ans=Ans*10+mod
	add r9, r9, r8
	mov r8, r10
b change
change_exit:

mov r1, r9		@Display the answer
mov r0, #1
swi SWI_PrInt 
swi SWI_Exit


