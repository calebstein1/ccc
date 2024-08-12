#ifndef CCC_OPCODES_H
#define CCC_OPCODES_H

#define OPCODE_COUNT 56

#define OPCODES_LIST   \
    X(ADC, adc_f)      \
    X(AND, and_f)      \
    X(ASL, asl_f)      \
    X(BCC, bcc_f)      \
    X(BCS, bcs_f)      \
    X(BEQ, beq_f)      \
    X(BIT, bit_f)      \
    X(BMI, bmi_f)      \
    X(BNE, bne_f)      \
    X(BPL, bpl_f)      \
    X(BRK, brk_f)      \
    X(BVC, bvc_f)      \
    X(BVS, bvs_f)      \
    X(CLC, clc_f)      \
    X(CLD, cld_f)      \
    X(CLI, cli_f)      \
    X(CLV, clv_f)      \
    X(CMP, cmp_f)      \
    X(CPX, cpx_f)      \
    X(CPY, cpy_f)      \
    X(DEC, dec_f)      \
    X(DEX, dex_f)      \
    X(DEY, dey_f)      \
    X(FOR, for_f)      \
    X(INC, inc_f)      \
    X(INX, inx_f)      \
    X(INY, iny_f)      \
    X(JMP, jmp_f)      \
    X(JSR, jsr_f)      \
    X(LDA, lda_f)      \
    X(LDX, ldx_f)      \
    X(LDY, ldy_f)      \
    X(LSR, lsr_f)      \
    X(NOP, nop_f)      \
    X(ORA, ora_f)      \
    X(PHA, pha_f)      \
    X(PHP, php_f)      \
    X(PLA, pla_f)      \
    X(PLP, plp_f)      \
    X(ROL, rol_f)      \
    X(ROR, ror_f)      \
    X(RTI, rti_f)      \
    X(RTS, rts_f)      \
    X(SBC, sbc_f)      \
    X(SEC, sec_f)      \
    X(SED, sed_f)      \
    X(SEI, sei_f)      \
    X(STA, sta_f)      \
    X(STX, stx_f)      \
    X(STY, sty_f)      \
    X(TAX, tax_f)      \
    X(TAY, tay_f)      \
    X(TSX, tsx_f)      \
    X(TXA, txa_f)      \
    X(TXS, txs_f)      \
    X(TYA, tya_f)

typedef enum {
#define X(opcode, ...) opcode,
    OPCODES_LIST
#undef X
} opcode_e;

#endif //CCC_OPCODES_H
