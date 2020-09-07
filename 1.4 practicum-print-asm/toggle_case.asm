.cpu cortex-m0
.text
.align 2
.global toggle_case

toggle_case:
    push { lr }
    cmp r0, #64
    bls done

    cmp r0, #123
    bhs done

    cmp r0, #90
    bls make_lower

    cmp r0, #97
    bhs make_upper

    b done

make_lower:
    add r0, #32
    b done

make_upper:
    sub r0, #32
    b done

done:
    bl uart_put_char
    pop { pc }