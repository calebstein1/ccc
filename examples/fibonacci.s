    .import printbuff, printnum ; from cclib

sbuff=$4020
hibyte=$4021
overflow=$fd
prev_carry_count=$fe
carry_count=$ff

    sta prev_carry_count
    sta carry_count
    sta overflow
    ldy #38
str_loop:
    lda string,y
    sta sbuff,y
    dey
    bpl str_loop
    jsr printbuff
    lda #1

    stx hibyte
    sta sbuff
    jsr printnum
    jsr printnum
    lda #2
    sta sbuff
    jsr printnum
    ldy #1
    sty $00

fib_loop:
    sta $0000,y
    clc
    adc $00,x
    bit overflow
    bvs do_carry
    bcc print_number
    pha
    lda #%01000000
    sta overflow
    pla
do_carry:
    pha
    lda carry_count
    pha
    adc prev_carry_count
    sta hibyte
    sta carry_count
    pla
    sta prev_carry_count
    pla
print_number:
    sta sbuff
    jsr printnum
increment_counters:
    inx
    iny
    cpx #21
    bne fib_loop
    rts

string:
    .byte "Fibonacci Sequence up to 24 numbers:", $0A, $00
