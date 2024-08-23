    .import printbuff ; from cclib

red=$2002
green=$2003
blue=$2004
ctrl=$4001
sbuff=$4020

    ldy #54
str_loop:
    lda string,y
    sta sbuff,y
    dey
    bpl str_loop
    jsr printbuff

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

string:
    .byte "Welcome to the CCC Rainbow example! Press 'z' to exit", $0A, $00
