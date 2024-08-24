.export waitnextframe, printbuff, printnum

waitnextframe:
    pha
    lda $2000
hold:
    cmp $2000
    beq hold
    pla
    rts

printbuff:
    pha
    lda #1
    sta $4018
    pla
    rts

printnum:
    pha
    lda #1
    sta $4019
    pla
    rts
