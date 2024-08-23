    .import printbuff ; from cclib

ctrl=$4001
sbuff=$4020

main:
    lda $2000
    pha
    lda ctrl
    and #%00000001
    beq check_secondary
    jsr print_primary
check_secondary:
    lda ctrl
    and #%00000010
    beq check_left
    jsr print_secondary
check_left:
    lda ctrl
    and #%00000100
    beq check_right
    jsr print_left
check_right:
    lda ctrl
    and #%00001000
    beq check_up
    jsr print_right
check_up:
    lda ctrl
    and #%00010000
    beq check_down
    jsr print_up
check_down:
    lda ctrl
    and #%00100000
    beq begin_hold
    jsr print_down
begin_hold:
    pla
hold:
    cmp $2000
    beq hold
    bvc main
    rts

print_primary:
    ldy #23
primary_loop:
    lda primary_str,y
    sta sbuff,y
    dey
    bpl primary_loop
    jsr printbuff
    rts

print_secondary:
    ldy #25
secondary_loop:
    lda secondary_str,y
    sta sbuff,y
    dey
    bpl secondary_loop
    jsr printbuff
    rts

print_left:
    ldy #20
left_loop:
    lda left_str,y
    sta sbuff,y
    dey
    bpl left_loop
    jsr printbuff
    rts

print_right:
    ldy #21
right_loop:
    lda right_str,y
    sta sbuff,y
    dey
    bpl right_loop
    jsr printbuff
    rts

print_up:
    ldy #18
up_loop:
    lda up_str,y
    sta sbuff,y
    dey
    bpl up_loop 
    jsr printbuff
    rts

print_down:
    ldy #20
down_loop:
    lda down_str,y
    sta sbuff,y
    dey
    bpl down_loop
    jsr printbuff
    rts

primary_str:
    .byte "Primary button pressed", $0A, $00

secondary_str:
    .byte "Secondary button pressed", $0A, $00

left_str:
    .byte "Left button pressed", $0A, $00

right_str:
    .byte "Right button pressed", $0A, $00

up_str:
    .byte "Up button pressed", $0A, $00

down_str:
    .byte "Down button pressed", $0A, $00
