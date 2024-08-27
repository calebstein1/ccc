#ifndef CCC_OPCODES_H
#define CCC_OPCODES_H

#define OPCODES_LIST		  \
	X(ADC_A, adca_f, "ADC")   \
	X(ADC_AX, adcax_f, "ADC") \
	X(ADC_AY, adcay_f, "ADC") \
	X(ADC_Z, adcz_f, "ADC")   \
	X(ADC_ZX, adczx_f, "ADC") \
	X(ADC_I, adci_f, "ADC")   \
	X(AND_A, anda_f, "AND")   \
	X(AND_AX, andax_f, "AND") \
	X(AND_AY, anday_f, "AND") \
	X(AND_Z, andz_f, "AND")   \
	X(AND_ZX, andzx_f, "AND") \
	X(AND_I, andi_f, "AND")   \
	X(ASL_A, asla_f, "ASL")   \
	X(ASL_AX, aslax_f, "ASL") \
	X(ASL_Z, aslz_f, "ASL")   \
	X(ASL_ZX, aslzx_f, "ASL") \
	X(ASL_AC, aslac_f, "ASL") \
	X(BCC, bcc_f, "BCC")	  \
	X(BCS, bcs_f, "BCS")	  \
	X(BEQ, beq_f, "BEQ")	  \
	X(BIT_A, bita_f, "BIT")   \
	X(BIT_Z, bitz_f, "BIT")   \
	X(BMI, bmi_f, "BMI")	  \
	X(BNE, bne_f, "BNE")	  \
	X(BPL, bpl_f, "BPL")	  \
	X(BRK, brk_f, "BRK")	  \
	X(BVC, bvc_f, "BVC")	  \
	X(BVS, bvs_f, "BVS")	  \
	X(CLC, clc_f, "CLC")	  \
	X(CLD, cld_f, "CLD")	  \
	X(CLI, cli_f, "CLI")	  \
	X(CLV, clv_f, "CLV")	  \
	X(CMP_A, cmpa_f, "CMP")   \
	X(CMP_AX, cmpax_f, "CMP") \
	X(CMP_AY, cmpay_f, "CMP") \
	X(CMP_Z, cmpz_f, "CMP")   \
	X(CMP_ZX, cmpzx_f, "CMP") \
	X(CMP_I, cmpi_f, "CMP")   \
	X(CPX_A, cpxa_f, "CPX")   \
	X(CPX_Z, cpxz_f, "CPX")   \
	X(CPX_I, cpxi_f, "CPX")   \
	X(CPY_A, cpya_f, "CPY")   \
	X(CPY_Z, cpyz_f, "CPY")   \
	X(CPY_I, cpyi_f, "CPY")   \
	X(DEC_A, deca_f, "DEC")   \
	X(DEC_AX, decax_f, "DEC") \
	X(DEC_Z, decz_f, "DEC")   \
	X(DEC_ZX, deczx_f, "DEC") \
	X(DEX, dex_f, "DEX")	  \
	X(DEY, dey_f, "DEY")	  \
	X(EOR_A, eora_f, "EOR")   \
	X(EOR_AX, eorax_f, "EOR") \
	X(EOR_AY, eoray_f, "EOR") \
	X(EOR_Z, eorz_f, "EOR")   \
	X(EOR_ZX, eorzx_f, "EOR") \
	X(EOR_I, eori_f, "EOR")   \
	X(INC_A, inca_f, "INC")   \
	X(INC_AX, incax_f, "INC") \
	X(INC_Z, incz_f, "INC")   \
	X(INC_ZX, inczx_f, "INC") \
	X(INX, inx_f, "INX")	  \
	X(INY, iny_f, "INY")	  \
	X(JMP_A, jmpa_f, "JMP")   \
	X(JSR, jsr_f, "JSR")	  \
	X(LDA_A, ldaa_f, "LDA")   \
	X(LDA_AX, ldaax_f, "LDA") \
	X(LDA_AY, ldaay_f, "LDA") \
	X(LDA_Z, ldaz_f, "LDA")   \
	X(LDA_ZX, ldazx_f, "LDA") \
	X(LDA_I, ldai_f, "LDA")   \
	X(LDX_A, ldxa_f, "LDX")   \
	X(LDX_AY, ldxay_f, "LDX") \
	X(LDX_Z, ldxz_f, "LDX")   \
	X(LDX_ZY, ldxzy_f, "LDX") \
	X(LDX_I, ldxi_f, "LDX")   \
	X(LDY_A, ldya_f, "LDY")   \
	X(LDY_AX, ldyax_f, "LDY") \
	X(LDY_Z, ldyz_f, "LDY")   \
	X(LDY_ZX, ldyzx_f, "LDY") \
	X(LDY_I, ldyi_f, "LDY")   \
	X(LSR_A, lsra_f, "LSR")   \
	X(LSR_AX, lsrax_f, "LSR") \
	X(LSR_Z, lsrz_f, "LSR")   \
	X(LSR_ZX, lsrzx_f, "LSR") \
	X(LSR_AC, lsrac_f, "LSR") \
	X(NOP, nop_f, "NOP")	  \
	X(ORA_A, oraa_f, "ORA")   \
	X(ORA_AX, oraax_f, "ORA") \
	X(ORA_AY, oraay_f, "ORA") \
	X(ORA_Z, oraz_f, "ORA")   \
	X(ORA_ZX, orazx_f, "ORA") \
	X(ORA_I, orai_f, "ORA")   \
	X(PHA, pha_f, "PHA")	  \
	X(PHP, php_f, "PHP")	  \
	X(PLA, pla_f, "PLA")	  \
	X(PLP, plp_f, "PLP")	  \
	X(ROL_A, rola_f, "ROL")   \
	X(ROL_AX, rolax_f, "ROL") \
	X(ROL_Z, rolz_f, "ROL")   \
	X(ROL_ZX, rolzx_f, "ROL") \
	X(ROL_AC, rolac_f, "ROL") \
	X(ROR_A, rora_f, "ROR")   \
	X(ROR_AX, rorax_f, "ROR") \
	X(ROR_Z, rorz_f, "ROR")   \
	X(ROR_ZX, rorzx_f, "ROR") \
	X(ROR_AC, rorac_f, "ROR") \
	X(RTI, rti_f, "RTI")	  \
	X(RTS, rts_f, "RTS")	  \
	X(SBC_A, sbca_f, "SBC")   \
	X(SBC_AX, sbcax_f, "SBC") \
	X(SBC_AY, sbcay_f, "SBC") \
	X(SBC_Z, sbcz_f, "SBC")   \
	X(SBC_ZX, sbczx_f, "SBC") \
	X(SBC_I, sbci_f, "SBC")   \
	X(SEC, sec_f, "SEC")	  \
	X(SED, sed_f, "SED")	  \
	X(SEI, sei_f, "SEI")	  \
	X(STA_A, staa_f, "STA")   \
	X(STA_AX, staax_f, "STA") \
	X(STA_AY, staay_f, "STA") \
	X(STA_Z, staz_f, "STA")   \
	X(STA_ZX, stazx_f, "STA") \
	X(STX_A, stxa_f, "STX")   \
	X(STX_Z, stxz_f, "STX")   \
	X(STX_ZY, stxzy_f, "STX") \
	X(STY_A, stya_f, "STY")   \
	X(STY_Z, styz_f, "STY")   \
	X(STY_ZX, styzx_f, "STY") \
	X(TAX, tax_f, "TAX")	  \
	X(TAY, tay_f, "TAY")	  \
	X(TSX, tsx_f, "TSX")	  \
	X(TXA, txa_f, "TXA")	  \
	X(TXS, txs_f, "TXS")	  \
	X(TYA, tya_f, "TYA")

typedef enum {
#define X(opcode, op_fn, str_lit) opcode,
	OPCODES_LIST
#undef X
	OPCODE_COUNT
} opcode_e;

static const char *str_tbl[] = {
#define X(opcode, op_fn, str_lit) str_lit,
	OPCODES_LIST
#undef X
};

#endif /* CCC_OPCODES_H */
