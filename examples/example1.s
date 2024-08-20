    STA $01
outer_loop:
    LDX #0
    INC $01
inner_loop:
    JSR add_value
    CPX $01
    CLC
    BNE inner_loop
    INY
    CPY #5
    CLC
    BNE outer_loop
    RTS

add_value:
    ADC $01
    INX
    RTS
