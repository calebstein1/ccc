    LDA #0
    TAY
    STA $3000
outer_loop:
    LDX #0
    INC $3000
inner_loop:
    JSR add_value
    CPX $3000
    BNE inner_loop
    INY
    CPY #5
    BNE outer_loop
    RTS

add_value:
    ADC $3000
    INX
    RTS
