#ifndef CCC_OPCODES_H
#define CCC_OPCODES_H

#define OPCODES_LIST          \
    X(END, nop_f, "END")      \
    X(ADC, adc_f, "ADC")      \
    X(AND, and_f, "AND")      \
    X(ASL, asl_f, "ASL")      \
    X(BCC, bcc_f, "BCC")      \
    X(BCS, bcs_f, "BCS")      \
    X(BEQ, beq_f, "BEQ")      \
    X(BIT, bit_f, "BIT")      \
    X(BMI, bmi_f, "BMI")      \
    X(BNE, bne_f, "BNE")      \
    X(BPL, bpl_f, "BPL")      \
    X(BRK, brk_f, "BRK")      \
    X(BVC, bvc_f, "BVC")      \
    X(BVS, bvs_f, "BVS")      \
    X(CLC, clc_f, "CLC")      \
    X(CLD, cld_f, "CLD")      \
    X(CLI, cli_f, "CLI")      \
    X(CLV, clv_f, "CLV")      \
    X(CMP, cmp_f, "CMP")      \
    X(CPX, cpx_f, "CPX")      \
    X(CPY, cpy_f, "CPY")      \
    X(DEC, dec_f, "DEC")      \
    X(DEX, dex_f, "DEX")      \
    X(DEY, dey_f, "DEY")      \
    X(FOR, for_f, "FOR")      \
    X(INC, inc_f, "INC")      \
    X(INX, inx_f, "INX")      \
    X(INY, iny_f, "INY")      \
    X(JMP, jmp_f, "JMP")      \
    X(JSR, jsr_f, "JSR")      \
    X(LDA, lda_f, "LDA")      \
    X(LDX, ldx_f, "LDX")      \
    X(LDY, ldy_f, "LDY")      \
    X(LSR, lsr_f, "LSR")      \
    X(NOP, nop_f, "NOP")      \
    X(ORA, ora_f, "ORA")      \
    X(PHA, pha_f, "PHA")      \
    X(PHP, php_f, "PHP")      \
    X(PLA, pla_f, "PLA")      \
    X(PLP, plp_f, "PLP")      \
    X(ROL, rol_f, "ROL")      \
    X(ROR, ror_f, "ROR")      \
    X(RTI, rti_f, "RTI")      \
    X(RTS, rts_f, "RTS")      \
    X(SBC, sbc_f, "SBC")      \
    X(SEC, sec_f, "SEC")      \
    X(SED, sed_f, "SED")      \
    X(SEI, sei_f, "SEI")      \
    X(STA, sta_f, "STA")      \
    X(STX, stx_f, "STX")      \
    X(STY, sty_f, "STY")      \
    X(TAX, tax_f, "TAX")      \
    X(TAY, tay_f, "TAY")      \
    X(TSX, tsx_f, "TSX")      \
    X(TXA, txa_f, "TXA")      \
    X(TXS, txs_f, "TXS")      \
    X(TYA, tya_f, "TYA")

typedef enum {
#define X(opcode, ...) opcode,
    OPCODES_LIST
#undef X
} opcode_e;

#endif //CCC_OPCODES_H
