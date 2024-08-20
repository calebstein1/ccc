    LDA #2
    LDY #1
    STY $00

fib_loop:
    STA $00,Y
    CLC
    ADC $00,X
    INX
    INY
    CPX #10
    BNE fib_loop
    RTS
