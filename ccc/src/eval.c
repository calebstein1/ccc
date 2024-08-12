#include "globals.h"
#include "opcodes.h"

void adc_f() {}

void and_f() {}

void asl_f() {}

void bcc_f() {}

void bcs_f() {}

void beq_f() {}

void bit_f() {}

void bmi_f() {}

void bne_f() {}

void bpl_f() {}

void brk_f() {}

void bvc_f() {}

void bvs_f() {}

void clc_f() {}

void cld_f() {}

void cli_f() {}

void clv_f() {}

void cmp_f() {}

void cpx_f() {}

void cpy_f() {}

void dec_f() {}

void dex_f() {}

void dey_f() {}

void for_f() {}

void inc_f() {}

void inx_f() {}

void iny_f() {}

void jmp_f() {}

void jsr_f() {}

void lda_f() {
    a = *pc++;
}

void ldx_f() {
    x = *pc++;
}

void ldy_f() {
    y = *pc++;
}

void lsr_f() {}

void nop_f() {}

void ora_f() {}

void pha_f() {}

void php_f() {}

void pla_f() {}

void plp_f() {}

void rol_f() {}

void ror_f() {}

void rti_f() {}

void rts_f() {}

void sbc_f() {}

void sec_f() {}

void sed_f() {}

void sei_f() {}

void sta_f() {}

void stx_f() {}

void sty_f() {}

void tax_f() {
    x = a;
}

void tay_f() {
    y = a;
}

void tsx_f() {}

void txa_f() {
    a = x;
}

void txs_f() {}

void tya_f() {
    a = y;
}

void (*eval_func[OPCODE_COUNT])() = {
#define X(opcode, op_fn, ...) op_fn,
        OPCODES_LIST
#undef X
};
