sbuff=$4020

    ldy #13
loop:
    lda string,y
    sta sbuff,y
    dey
    bpl loop
    lda #1
    sta $4018
    rts

string:
    .byte "Hello, world!", $00
