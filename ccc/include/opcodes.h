#ifndef CCC_OPCODES_H
#define CCC_OPCODES_H

#define OPCODES_LIST               \
    X(ADC_A, adca_f, "ADC", ...)   \
    X(ADC_AX, adcax_f, "ADC", ...) \
    X(ADC_AY, adcay_f, "ADC", ...) \
    X(ADC_Z, adcz_f, "ADC", ...)   \
    X(ADC_ZX, adczx_f, "ADC", ...) \
    X(ADC_ZY, adczy_f, "ADC", ...) \
    X(ADC_I, adci_f, "ADC", ...)   \
    X(AND_A, anda_f, "AND", ...)   \
    X(AND_AX, andax_f, "AND", ...) \
    X(AND_AY, anday_f, "AND", ...) \
    X(AND_Z, andz_f, "AND", ...)   \
    X(AND_ZX, andzx_f, "AND", ...) \
    X(AND_ZY, andzy_f, "AND", ...) \
    X(AND_I, andi_f, "AND", ...)   \
    X(ASL_A, asla_f, "ASL", ...)   \
    X(ASL_AX, aslax_f, "ASL", ...) \
    X(ASL_AY, aslay_f, "ASL", ...) \
    X(ASL_Z, aslz_f, "ASL", ...)   \
    X(ASL_ZX, aslzx_f, "ASL", ...) \
    X(ASL_ZY, aslzy_f, "ASL", ...) \
    X(ASL_AC, aslac_f, "ASL", ...) \
    X(BCC, bcc_f, "BCC", ...)      \
    X(BCC_65, bcc65_f, "BCC", ...) \
    X(BCS, bcs_f, "BCS", ...)      \
    X(BCS_65, bcs65_f, "BCS", ...) \
    X(BEQ, beq_f, "BEQ", ...)      \
    X(BEQ_65, beq65_f, "BEQ", ...) \
    X(BIT_A, bita_f, "BIT", ...)   \
    X(BIT_AX, bitax_f, "BIT", ...) \
    X(BIT_AY, bitay_f, "BIT", ...) \
    X(BIT_Z, bitz_f, "BIT", ...)   \
    X(BIT_ZX, bitzx_f, "BIT", ...) \
    X(BIT_ZY, bitzy_f, "BIT", ...) \
    X(BMI, bmi_f, "BMI", ...)      \
    X(BMI_65, bmi65_f, "BMI", ...) \
    X(BNE, bne_f, "BNE", ...)      \
    X(BNE_65, bne65_f, "BNE", ...) \
    X(BPL, bpl_f, "BPL", ...)      \
    X(BPL_65, bpl65_f, "BPL", ...) \
    X(BRK, brk_f, "BRK", ...)      \
    X(BVC, bvc_f, "BVC", ...)      \
    X(BVC_65, bvc65_f, "BVC", ...) \
    X(BVS, bvs_f, "BVS", ...)      \
    X(BVS_65, bvs65_f, "BVS", ...) \
    X(CLC, clc_f, "CLC", ...)      \
    X(CLD, cld_f, "CLD", ...)      \
    X(CLI, cli_f, "CLI", ...)      \
    X(CLV, clv_f, "CLV", ...)      \
    X(CMP_A, cmpa_f, "CMP", ...)   \
    X(CMP_AX, cmpax_f, "CMP", ...) \
    X(CMP_AY, cmpay_f, "CMP", ...) \
    X(CMP_Z, cmpz_f, "CMP", ...)   \
    X(CMP_ZX, cmpzx_f, "CMP", ...) \
    X(CMP_ZI, cmpzy_f, "CMP", ...) \
    X(CMP_I, cmpi_f, "CMP", ...)   \
    X(CPX_A, cpxa_f, "CPX", ...)   \
    X(CPX_AX, cpxax_f, "CPX", ...) \
    X(CPX_AY, cpxay_f, "CPX", ...) \
    X(CPX_Z, cpxz_f, "CPX", ...)   \
    X(CPX_ZX, cpxzx_f, "CPX", ...) \
    X(CPX_ZY, cpxzy_f, "CPX", ...) \
    X(CPX_I, cpxi_f, "CPX", ...)   \
    X(CPY_A, cpya_f, "CPY", ...)   \
    X(CPY_AX, cpyax_f, "CPY", ...) \
    X(CPY_AY, cpyzy_f, "CPY", ...) \
    X(CPY_Z, cpyz_f, "CPY", ...)   \
    X(CPY_ZX, cpyzx_f, "CPY", ...) \
    X(CPY_ZY, cpyzy_f, "CPY", ...) \
    X(CPY_I, cpyi_f, "CPY", ...)   \
    X(DEC_A, deca_f, "DEC", ...)   \
    X(DEC_AX, decax_f, "DEC", ...) \
    X(DEC_AY, decay_f, "DEC", ...) \
    X(DEC_Z, decz_f, "DEC", ...)   \
    X(DEC_ZX, deczx_f, "DEC", ...) \
    X(DEC_ZY, deczy_f, "DEC", ...) \
    X(DEX, dex_f, "DEX", ...)      \
    X(DEY, dey_f, "DEY", ...)      \
    X(EOR_A, eora_f, "EOR", ...)   \
    X(EOR_AX, eorax_f, "EOR", ...) \
    X(EOR_AY, eoray_f, "EOR", ...) \
    X(EOR_Z, eorz_f, "EOR", ...)   \
    X(EOR_ZX, eorzx_f, "EOR", ...) \
    X(EOR_ZY, eorzy_f, "EOR", ...) \
    X(EOR_I, eori_f, "EOR", ...) \
    X(INC_A, inca_f, "INC", ... )   \
    X(INC_AX, incax_f, "INC", ...) \
    X(INC_AY, incay_f, "INC", ...) \
    X(INC_Z, incz_f, "INC", ...)   \
    X(INC_ZX, inczx_f, "INC", ...) \
    X(INC_ZY, inczy_f, "INC", ...) \
    X(INX, inx_f, "INX", ...)      \
    X(INY, iny_f, "INY", ...)      \
    X(JMP_A, jmpa_f, "JMP", ...)   \
    X(JMP_AX, jmpax_f, "JMP", ...) \
    X(JMP_AY, jmpay_f, "JMP", ...) \
    X(JMP_Z, jmpz_f, "JMP", ...)   \
    X(JMP_ZX, jmpzx_f, "JMP", ...) \
    X(JMP_ZY, jmpzy_f, "JMP", ...) \
    X(JSR, jsr_f, "JSR", ...)      \
    X(LDA_A, ldaa_f, "LDA", ...)   \
    X(LDA_AX, ldaax_f, "LDA", ...) \
    X(LDA_AY, ldaay_f, "LDA", ...) \
    X(LDA_Z, ldaz_f, "LDA", ...)   \
    X(LDA_ZX, ldazx_f, "LDA", ...) \
    X(LDA_ZY, ldazy_f, "LDA", ...) \
    X(LDA_I, ldai_f, "LDA", ...)   \
    X(LDX_A, ldxa_f, "LDX", ...)   \
    X(LDX_AX, ldxax_f, "LDX", ...) \
    X(LDX_AY, ldxay_f, "LDX", ...) \
    X(LDX_Z, ldxz_f, "LDX", ...)   \
    X(LDX_ZX, ldxzx_f, "LDX", ...) \
    X(LDX_ZY, ldxzy_f, "LDX", ...) \
    X(LDX_I, ldxi_f, "LDX", ...)   \
    X(LDY_A, ldya_f, "LDY", ...)   \
    X(LDY_AX, ldyax_f, "LDY", ...) \
    X(LDY_AY, ldyay_f, "LDY", ...) \
    X(LDY_Z, ldyz_f, "LDY", ...)   \
    X(LDY_ZX, ldyzx_f, "LDY", ...) \
    X(LDY_ZY, ldyzy_f, "LDY", ...) \
    X(LDY_I, ldyi_f, "LDY", ...)   \
    X(LSR_A, lsra_f, "LSR", ...)   \
    X(LSR_AX, lsrax_f, "LSR", ...) \
    X(LSR_AY, lsray_f, "LSR", ...) \
    X(LSR_Z, lsrz_f, "LSR", ...)   \
    X(LSR_ZX, lsrzx_f, "LSR", ...) \
    X(LSR_ZY, lsrzy_f, "LSR", ...) \
    X(LSR_AC, lsrac_f, "LSR", ...) \
    X(NOP, nop_f, "NOP", ...)      \
    X(ORA_A, oraa_f, "ORA", ...)   \
    X(ORA_AX, oraax_f, "ORA", ...) \
    X(ORA_AY, oraay_f, "ORA", ...) \
    X(ORA_Z, oraz_f, "ORA", ...)   \
    X(ORA_ZX, orazx_f, "ORA", ...) \
    X(ORA_ZY, orazy_f, "ORA", ...) \
    X(ORA_I, orai_f, "ORA", ...)   \
    X(PHA, pha_f, "PHA", ...)      \
    X(PHP, php_f, "PHP", ...)      \
    X(PLA, pla_f, "PLA", ...)      \
    X(PLP, plp_f, "PLP", ...)      \
    X(ROL_A, rola_f, "ROL", ...)   \
    X(ROL_AX, rolax_f, "ROL", ...) \
    X(ROL_AY, rolay_f, "ROL", ...) \
    X(ROL_Z, rolz_f, "ROL", ...)   \
    X(ROL_ZX, rolzx_f, "ROL", ...) \
    X(ROL_ZY, rolzy_f, "ROL", ...) \
    X(ROL_AC, rolac_f, "ROL", ...) \
    X(ROR_A, rora_f, "ROR", ...)   \
    X(ROR_AX, rorax_f, "ROR", ...) \
    X(ROR_AY, roray_f, "ROR", ...) \
    X(ROR_Z, rorz_f, "ROR", ...)   \
    X(ROR_ZX, rorzx_f, "ROR", ...) \
    X(ROR_ZY, rorzy_f, "ROR", ...) \
    X(ROR_AC, rorac_f, "ROR", ...) \
    X(RTI, rti_f, "RTI", ...)      \
    X(RTS, rts_f, "RTS", ...)      \
    X(SBC_A, sbca_f, "SBC", ...)   \
    X(SBC_AX, sbcax_f, "SBC", ...) \
    X(SBC_AY, sbcay_f, "SBC", ...) \
    X(SBC_Z, sbcz_f, "SBC", ...)   \
    X(SBC_ZX, sbczx_f, "SBC", ...) \
    X(SBC_ZY, sbczy_f, "SBC", ...) \
    X(SBC_I, sbci_f, "SBC", ...)   \
    X(SEC, sec_f, "SEC", ...)      \
    X(SED, sed_f, "SED", ...)      \
    X(SEI, sei_f, "SEI", ...)      \
    X(STA_A, staa_f, "STA", ...)   \
    X(STA_AX, staax_f, "STA", ...) \
    X(STA_AY, staay_f, "STA", ...) \
    X(STA_Z, staz_f, "STA", ...)   \
    X(STA_ZX, stazx_f, "STA", ...) \
    X(STA_ZY, stazy_f, "STA", ...) \
    X(STX_A, stxa_f, "STX", ...)   \
    X(STX_AX, stxax_f, "STX", ...) \
    X(STX_AY, stxay_f, "STX", ...) \
    X(STX_Z, stxz_f, "STX", ...)   \
    X(STX_ZX, stxzx_f, "STX", ...) \
    X(STX_ZY, stxzy_f, "STX", ...) \
    X(STY_A, stya_f, "STY", ...)   \
    X(STY_AX, styax_f, "STY", ...) \
    X(STY_AY, styay_f, "STY", ...) \
    X(STY_Z, styz_f, "STY", ...)   \
    X(STY_ZX, styzx_f, "STY", ...) \
    X(STY_ZY, styzy_f, "STY", ...) \
    X(TAX, tax_f, "TAX", ...)      \
    X(TAY, tay_f, "TAY", ...)      \
    X(TSX, tsx_f, "TSX", ...)      \
    X(TXA, txa_f, "TXA", ...)      \
    X(TXS, txs_f, "TXS", ...)      \
    X(TYA, tya_f, "TYA", ...)

typedef enum {
#define X(opcode, ...) opcode,
    OPCODES_LIST
#undef X
} opcode_e;

static const opcode_e t6502[] = {
        BRK, NOP, NOP, NOP, NOP, ORA_Z, ASL_Z, NOP, PHP, ORA_I, ASL_AC, NOP, NOP, ORA_A, ASL_A, NOP,
        BPL_65, NOP, NOP, NOP, NOP, ORA_ZX, ASL_ZX, NOP, CLC, ORA_AY, NOP, NOP, NOP, ORA_AX, ASL_AX, NOP,
        JSR, NOP, NOP, NOP,  BIT_Z, AND_Z, ROL_Z, NOP, PLP, AND_I, ROL_AC, NOP, BIT_A, AND_A, ROL_A, NOP,
        BMI_65, NOP, NOP, NOP, NOP, AND_ZX, ROL_ZX, NOP, SEC, AND_AY, NOP, NOP, NOP, AND_AX, ROL_AX, NOP,
        RTI, NOP, NOP, NOP, NOP, EOR_Z, LSR_Z, NOP, PHA, EOR_I, LSR_AC, NOP, JMP_A, EOR_A, LSR_A, NOP,
        BVC_65, NOP, NOP, NOP, NOP, EOR_ZX, LSR_ZX, NOP, CLI, EOR_AY, NOP, NOP, NOP, EOR_AX, LSR_AX, NOP,
        RTS, NOP, NOP, NOP, NOP, ADC_Z, ROR_Z, NOP, PLA, ADC_I, ROR_AC, NOP, NOP, ADC_A, ROR_A, NOP,
        BVS_65, NOP, NOP, NOP, NOP, ADC_ZX, ROR_ZX, NOP, SEI, ADC_AY, NOP, NOP, NOP, ADC_AX, ROR_AX, NOP,
        NOP, NOP, NOP, NOP, STY_Z, STA_Z, STX_Z, NOP, DEY, NOP, TXA, NOP, STY_A, STA_A, STX_A, NOP,
        BCC_65, NOP, NOP, NOP, STY_ZX, STA_ZX, STX_ZY, NOP, TYA, STA_AY, TXS, NOP, NOP, STA_AX, NOP, NOP,
        LDY_I, NOP, LDX_I, NOP, LDY_Z, LDA_Z, LDX_Z, NOP, TAY, LDA_I, TAX, NOP, LDY_A, LDA_A, LDX_A, NOP,
        BCS_65, NOP, NOP, NOP, LDY_ZX, LDA_ZX, LDX_ZY, NOP, CLV, LDA_AY, TSX, NOP, LDY_AX, LDA_AX, LDX_AY, NOP,
        CPY_I, NOP, NOP, NOP, CPY_Z, CMP_Z, DEC_Z, NOP, INY, CMP_I, DEX, NOP, CPY_A, CMP_A, DEC_A, NOP,
        BNE_65, NOP, NOP, NOP, NOP, CMP_ZX, DEC_ZX, NOP, CLD, CMP_AY, NOP, NOP, NOP, CMP_AX, DEC_AX, NOP,
        CPX_I, NOP, NOP, NOP, CPX_Z, SBC_Z, INC_Z, NOP, INX, SBC_I, NOP, NOP, CPX_A, SBC_A, INC_A, NOP,
        BEQ_65, NOP, NOP, NOP, NOP, SBC_ZX, INC_ZX, NOP, SED, SBC_AY, NOP, NOP, NOP, SBC_AX, INC_AX, NOP
};

static const char *str_tbl[] = {
#define X(opcode, op_fn, str_lit, ...) str_lit,
        OPCODES_LIST
#undef X
};

#endif //CCC_OPCODES_H
