   .cpu cortex-m0
   .text
   .align 1
   .global print_asciz

print_asciz:
   push { r5, lr }
   mov  r5, r0
loop: 
   ldrb r0, [ r5 ]   	//laad in
   add  r0, r0, #0		// 
   beq  done			//checkt of het gelijk is aan 0
   bl   isupper
   bl   uart_put_char	//returnt karakter op r0?
   add  r5, r5, #1
   b    loop
done: 
   pop  { r5, pc }
   
application:


isupper:
    mov r1, r0
    sub r1, r1, #'A'
    blt islower
    mov r1, r0
    sub r1, r1, #'Z'
    bgt islower
    mov r2, #'A'
    sub r2, #'a'
    sub r0, r0, r2
    b return

islower:
    mov r1, r0
    sub r1, r1, #'a'
    blt return
    mov r1, r0
    sub r1, r1, #'z'
    bgt return
    mov r2, #'A'
    sub r2, #'a'
    add r0, r0, r2
    b return 
    
return:    
    mov pc, lr
