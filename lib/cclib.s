.export printbuff, printnum

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
