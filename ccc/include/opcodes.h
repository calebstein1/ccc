#ifndef CCC_OPCODES_H
#define CCC_OPCODES_H

#define OPCODES_LIST          \
    X(ADC_A, adca_f, "ADC")   \
    X(ADC_AX, adcax_f, "ADC") \
    X(ADC_AY, adcay_f, "ADC") \
    X(ADC_Z, adcz_f, "ADC")   \
    X(ADC_ZX, adczx_f, "ADC") \
    X(ADC_ZY, adczy_f, "ADC") \
    X(ADC_I, adci_f, "ADC")   \
    X(AND, and_f, "AND")      \
    X(ASL, asl_f, "ASL")      \
    X(BCC_A, bcca_f, "BCC")      \
    X(BCC_AX, bccax_f, "BCC")      \
    X(BCC_AY, bccay_f, "BCC")      \
    X(BCC_Z, bccz_f, "BCC")      \
    X(BCC_ZX, bcczx_f, "BCC")      \
    X(BCC_ZY, bcczy_f, "BCC")      \
    X(BCS_A, bcsa_f, "BCS")      \
    X(BCS_AX, bcsax_f, "BCS")      \
    X(BCS_AY, bcsay_f, "BCS")      \
    X(BCS_Z, bcsz_f, "BCS")      \
    X(BCS_ZX, bcszx_f, "BCS")      \
    X(BCS_ZY, bcszy_f, "BCS")      \
    X(BEQ_A, beqa_f, "BEQ")      \
    X(BEQ_AX, beqax_f, "BEQ")      \
    X(BEQ_AY, beqay_f, "BEQ")      \
    X(BEQ_Z, beqz_f, "BEQ")      \
    X(BEQ_ZX, beqzx_f, "BEQ")      \
    X(BEQ_ZY, beqzy_f, "BEQ")      \
    X(BIT, bit_f, "BIT")      \
    X(BMI, bmi_f, "BMI")      \
    X(BNE_A, bnea_f, "BNE")      \
    X(BNE_AX, bneax_f, "BNE")      \
    X(BNE_AY, bneay_f, "BNE")      \
    X(BNE_Z, bnez_f, "BNE")      \
    X(BNE_ZX, bnezx_f, "BNE")      \
    X(BNE_ZY, bnezy_f, "BNE")      \
    X(BPL, bpl_f, "BPL")      \
    X(BRK, brk_f, "BRK")      \
    X(BVC, bvc_f, "BVC")      \
    X(BVS, bvs_f, "BVS")      \
    X(CLC, clc_f, "CLC")      \
    X(CLD, cld_f, "CLD")      \
    X(CLI, cli_f, "CLI")      \
    X(CLV, clv_f, "CLV")      \
    X(CMP_A, cmpa_f, "CMP")      \
    X(CMP_AX, cmpax_f, "CMP")      \
    X(CMP_AY, cmpay_f, "CMP")      \
    X(CMP_Z, cmpz_f, "CMP")      \
    X(CMP_ZX, cmpzx_f, "CMP")      \
    X(CMP_ZI, cmpzy_f, "CMP")      \
    X(CMP_I, cmpi_f, "CMP")      \
    X(CPX_A, cpxa_f, "CPX")      \
    X(CPX_AX, cpxax_f, "CPX")      \
    X(CPX_AY, cpxay_f, "CPX")      \
    X(CPX_Z, cpxz_f, "CPX")      \
    X(CPX_ZX, cpxzx_f, "CPX")      \
    X(CPX_ZY, cpxzy_f, "CPX")      \
    X(CPX_I, cpxi_f, "CPX")      \
    X(CPY_A, cpya_f, "CPY")      \
    X(CPY_AX, cpyax_f, "CPY")      \
    X(CPY_AY, cpyzy_f, "CPY")      \
    X(CPY_Z, cpyz_f, "CPY")      \
    X(CPY_ZX, cpyzx_f, "CPY")      \
    X(CPY_ZY, cpyzy_f, "CPY")      \
    X(CPY_I, cpyi_f, "CPY")      \
    X(DEC_A, deca_f, "DEC")      \
    X(DEC_AX, decax_f, "DEC")      \
    X(DEC_AY, decay_f, "DEC")      \
    X(DEC_Z, decz_f, "DEC")      \
    X(DEC_ZX, deczx_f, "DEC")      \
    X(DEC_ZY, deczy_f, "DEC")      \
    X(DEX, dex_f, "DEX")      \
    X(DEY, dey_f, "DEY")      \
    X(FOR, for_f, "FOR")      \
    X(INC_A, inca_f, "INC")      \
    X(INC_AX, incax_f, "INC")      \
    X(INC_AY, incay_f, "INC")      \
    X(INC_Z, incz_f, "INC")      \
    X(INC_ZX, inczx_f, "INC")      \
    X(INC_ZY, inczy_f, "INC")      \
    X(INX, inx_f, "INX")      \
    X(INY, iny_f, "INY")      \
    X(JMP_A, jmpa_f, "JMP")      \
    X(JMP_AX, jmpax_f, "JMP")      \
    X(JMP_AY, jmpay_f, "JMP")      \
    X(JMP_Z, jmpz_f, "JMP")      \
    X(JMP_ZX, jmpzx_f, "JMP")      \
    X(JMP_ZY, jmpzy_f, "JMP")      \
    X(JSR, jsr_f, "JSR")      \
    X(LDA_A, ldaa_f, "LDA")      \
    X(LDA_AX, ldaax_f, "LDA")      \
    X(LDA_AY, ldaay_f, "LDA")      \
    X(LDA_Z, ldaz_f, "LDA")      \
    X(LDA_ZX, ldazx_f, "LDA")      \
    X(LDA_ZY, ldazy_f, "LDA")      \
    X(LDA_I, ldai_f, "LDA")      \
    X(LDX_A, ldxa_f, "LDX")      \
    X(LDX_AX, ldxax_f, "LDX")      \
    X(LDX_AY, ldxay_f, "LDX")      \
    X(LDX_Z, ldxz_f, "LDX")      \
    X(LDX_ZX, ldxzx_f, "LDX")      \
    X(LDX_ZY, ldxzy_f, "LDX")      \
    X(LDX_I, ldxi_f, "LDX")      \
    X(LDY_A, ldya_f, "LDY")      \
    X(LDY_AX, ldyax_f, "LDY")      \
    X(LDY_AY, ldyay_f, "LDY")      \
    X(LDY_Z, ldyz_f, "LDY")      \
    X(LDY_ZX, ldyzx_f, "LDY")      \
    X(LDY_ZY, ldyzy_f, "LDY")      \
    X(LDY_I, ldyi_f, "LDY")      \
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
    X(STA_A, staa_f, "STA")      \
    X(STA_AX, staax_f, "STA")      \
    X(STA_AY, staay_f, "STA")      \
    X(STA_Z, staz_f, "STA")      \
    X(STA_ZX, stazx_f, "STA")      \
    X(STA_ZY, stazy_f, "STA")      \
    X(STX_A, stxa_f, "STX")      \
    X(STX_AX, stxax_f, "STX")      \
    X(STX_AY, stxay_f, "STX")      \
    X(STX_Z, stxz_f, "STX")      \
    X(STX_ZX, stxzx_f, "STX")      \
    X(STX_ZY, stxzy_f, "STX")      \
    X(STY_A, stya_f, "STY")      \
    X(STY_AX, styax_f, "STY")      \
    X(STY_AY, styay_f, "STY")      \
    X(STY_Z, styz_f, "STY")      \
    X(STY_ZX, styzx_f, "STY")      \
    X(STY_ZY, styzy_f, "STY")      \
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

static char *str_tbl[] = {
#define X(opcode, op_fn, str_lit, ...) str_lit,
        OPCODES_LIST
#undef X
};

#endif //CCC_OPCODES_H
