.cpu cortex-m0
answer: 
    .asciz "1.4: Hello world, the ANSWER is 42! @[]`{}~\n"
.align 1
.text
.global print_asciz
.global application

application:
    push { lr }
    ldr r0, =answer
    bl print_asciz
    pop { pc }

print_asciz:
    push { r5, lr }
    mov r5, r0
loop:
    ldrb r0, [ r5 ]
    add r0, r0, #0
    beq done
    bl toggle_case
    bl uart_put_char
    add r5, r5, #1
    b loop
    pop { r5, pc }

toggle_case:
    push { lr }
    cmp r0, #'A'                    
    blt done
    cmp r0, #'Z'
    blt caps
    cmp r0, #'a'                        
    blt done
    cmp r0, #'z'
    blt small
    b done

caps:
    add r0, #('a' - 'A')              
    b done

small:
    sub r0, #('a' - 'A')              
    b done

done:
    pop { pc }