    .import drawloop, printbuff ; from cclib

frame=$2000
red=$2002
green=$2003
blue=$2004
ctrl=$4001
sbuff=$4020

red_dir=$00
green_dir=$01
blue_dir=$02

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
draw_loop:
    jsr drawloop
    lda ctrl
    and #1
    bne leave
    jsr mod_red
    jsr mod_green
    jsr mod_blue
    bvc draw_loop
leave:
    rts

check_min:
    cmp #0
    beq set_dir_up
    rts
set_dir_up:
    ldx #1
    rts

check_max:
    cmp #$ff
    beq set_dir_down
    rts
set_dir_down:
    ldx #0
    rts

mod_red:
    lda red
    ldx red_dir
    jsr check_min
    jsr check_max
    stx red_dir
    cpx #0
    beq dec_red
    inc red
    rts
dec_red:
    dec red
    rts

mod_green:
    lda green
    ldx green_dir
    jsr check_min
    jsr check_max
    stx green_dir
    cpx #0
    beq dec_green
    inc green
    rts
dec_green:
    dec green
    rts

mod_blue:
    lda blue
    ldx blue_dir
    jsr check_min
    jsr check_max
    stx blue_dir
    cpx #0
    beq dec_blue
    inc blue
    rts
dec_blue:
    dec blue
    rts

string:
    .byte "Welcome to the CCC Rainbow example! Press 'z' to exit", $0A, $00
