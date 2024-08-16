    LDA #2
    LDY #1
    STY $00,X

fib_loop:
    STA $00,Y
    ADC $00,X
    INX
    INY
    CPX #10
    BNE fib_loop
    RTS
