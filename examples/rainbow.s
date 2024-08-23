red=$2002
green=$2003
blue=$2004
ctrl=$4001

    ldx #0
    lda #$C0
    sta red
    lda #$80
    sta green
    lda #$40
    sta blue
loop:
    lda ctrl
    and #1
    bne leave
    lda $2000
    cmp #36
    bne cont_lp
    jsr reset_frame
cont_lp:
    cmp #0
    bne loop
    dec red
    dec green
    dec blue
    bvc loop
leave:
    rts

reset_frame:
    stx $2000
    rts
