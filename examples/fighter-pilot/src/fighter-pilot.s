    .import waitnextframe ; from cclib

    p_slot=$2200
    p_x=$2202
    p_sx=$2204
    p_y=$2203
    p_sy=$2205

    e_slot=$2208
    e_x=$220a
    e_sx=$220c
    e_y=$220b
    e_sy=$220d

    ctrl=$4001

init:
    lda #$ab
    sta $2002
    lda #$db
    sta $2003
    lda #$e3
    sta $2004
    jsr init_player
    jsr init_enemy
main:
    jsr waitnextframe
    jsr move_player
    jsr move_enemy
    jmp main
    rts


    ; Subroutines
init_player:
    ldx #0
    lda #1
    jsr str_pslot_incx
    lda #0
    jsr str_pslot_incx
    lda #32
    jsr str_pslot_incx
    jsr str_pslot_incx
    lda #0
    jsr str_pslot_incx
    jsr str_pslot_incx
    jsr str_pslot_incx
    rts

init_enemy:
    ldx #0
    lda #2
    jsr str_eslot_incx
    lda #0
    jsr str_eslot_incx
    lda #64
    jsr str_eslot_incx
    jsr str_eslot_incx
    lda #0
    jsr str_eslot_incx
    jsr str_eslot_incx
    lda #1
    jsr str_eslot_incx
    rts

str_pslot_incx:
    sta p_slot,x
    inx
    rts

str_eslot_incx:
    sta e_slot,x
    inx
    rts

move_player:
    lda ctrl
    and #%00000100
    beq check_right
    lda p_sx
    clc
    sbc #$40
    sta p_sx
    bcc check_right
    dec p_x
check_right:
    lda ctrl
    and #%00001000
    beq check_up
    lda p_sx
    clc
    adc #$40
    sta p_sx
    bcc check_up
    inc p_x
check_up:
    lda ctrl
    and #%00010000
    beq check_down
    lda p_sy
    clc
    sbc #$40
    sta p_sy
    bcc check_down
    dec p_y
check_down:
    lda ctrl
    and #%00100000
    beq end_move
    lda p_sy
    clc
    adc #$40
    sta p_sy
    bcc end_move
    inc p_y
end_move:
    rts

move_enemy:
    lda e_y
    cmp p_y
    beq end_enemy_move
    lda e_sy
    bcs move_enemy_down
    clc
    sbc #$20
    sta e_sy
    bcc end_enemy_move
    dec e_y
    jmp end_enemy_move
move_enemy_down:
    adc #$20
    sta e_sy
    bcc end_enemy_move
    inc e_y
end_enemy_move:
    rts

