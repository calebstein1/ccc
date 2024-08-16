    STA $01
outer_loop:
    LDX #0
    INC $01
inner_loop:
    JSR add_value
    CPX $01
    BNE inner_loop
    INY
    CPY #5
    BNE outer_loop
    RTS

add_value:
    ADC $01
    INX
    RTS
