    LDA #0
    TAY
    STA $3000
outer_loop:
    LDX #0
    INC $3000
inner_loop:
    ADC $3000
    INX
    CPX $3000
    BNE inner_loop
    INY
    CPY #5
    BNE outer_loop

