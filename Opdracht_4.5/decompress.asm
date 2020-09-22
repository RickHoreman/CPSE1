    .cpu cortex-m0 
    .text 
    .align 4 
    .global decompress


decompress:
    push { r4-r7, lr }
    ldr r5, =compressed
    b loop
    
loop:
    ldrb r0, [r5]
    cmp r0, #0
    beq done

    cmp r0, #'@'
    bne print

    /*na @ pakt deze het eerst volgende getal*/
    add r5, r5, #1
    ldrb r0, [r5]
    sub r0, r0, #'0'
    mov r6, r0
    
    /*na @ pakt deze het tweede getal*/
    add r5, r5, #1
    ldrb r0, [r5]
    sub r0, r0, #'0'
    mov r7, r0

    ldr r2, =counter
    ldr r3, [r2]
    ldr r2, =buffer
    sub r2, r2, #1
    add r2, r2, r3
    sub r4, r2, r6
    bl add

    b loop
add:
    ldrb r0, [r4]
    
    cmp r7, #0
    beq returntoloop   
    
    bl bufferprint
    add r4, r4, #1
    sub r7, r7, #1
    b add
returntoloop:
    add r5, r5, #1
    b loop
print:
    bl bufferprint
    b returntoloop
bufferprint:
    push { lr }
    ldr r2, =counter
    ldr r3, [r2]
    ldr r2, =buffer
    add r3, r3, r2
    strb r0, [r3]

    ldr r2, =counter
    ldr r3, [r2]
    add r3, r3, #1
    str r3, [r2] 

    bl uart_put_char
    pop { pc }
done:
    pop { r4-r7, pc }

.bss
buffer:
    .skip 4100
counter:
    .skip 4