#include <stdint.h>

#include "globals.h"
#include "opcodes.h"
#include "cpu.h"

void adc_f() {
    uint8_t la = a;
    if (*(pc + 1) == NOP) {
        a += (*pc++ + GET_C);
    } else {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        a += (*(prg_ram + MAKE_WORD) + GET_C);
    }
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
}

void and_f() {}

void asl_f() {}

void bcc_f() {}

void bcs_f() {}

void beq_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bit_f() {}

void bmi_f() {}

void bne_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bpl_f() {}

void brk_f() {}

void bvc_f() {}

void bvs_f() {}

void clc_f() {
    UNSET_C;
}

void cld_f() {}

void cli_f() {}

void clv_f() {}

void cmp_f() {
    if (*(pc + 1) == NOP) {
        if (a - *pc++) {
            UNSET_Z;
        } else {
            SET_Z;
        }
        return;
    }
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (a - *(prg_ram + MAKE_WORD)) {
        UNSET_Z;
    } else {
        SET_Z;
    }
}

void cpx_f() {
    if (*(pc + 1) == NOP) {
        if (x - *pc++) {
            UNSET_Z;
        } else {
            SET_Z;
        }
        return;
    }
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (x - *(prg_ram + MAKE_WORD)) {
        UNSET_Z;
    } else {
        SET_Z;
    }
}

void cpy_f() {
    if (*(pc + 1) == NOP) {
        if (y - *pc++) {
            UNSET_Z;
        } else {
            SET_Z;
        }
        return;
    }
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (y - *(prg_ram + MAKE_WORD)) {
        UNSET_Z;
    } else {
        SET_Z;
    }
}

void dec_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) -= 1;
}

void dex_f() {
    x--;
}

void dey_f() {
    y--;
}

void for_f() {}

void inc_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) += 1;
}

void inx_f() {
    x++;
}

void iny_f() {
    y++;
}

void jmp_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    pc = prg_ram + MAKE_WORD;
}

void jsr_f() {
    uint8_t low = PC_LOW + 2;
    uint8_t hi = PC_HI;
    if (low <= 1) {
        hi++;
    }
    STACK_PUSH(hi);
    STACK_PUSH(low);

    low = *pc++;
    hi = *pc++;
    pc = prg_ram + MAKE_WORD;
}

void lda_f() {
    if (*(pc + 1) == NOP) {
        a = *pc++;
        return;
    }
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    a = *(prg_ram + MAKE_WORD);
}

void ldx_f() {
    if (*(pc + 1) == NOP) {
        x = *pc++;
        return;
    }
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    x = *(prg_ram + MAKE_WORD);
}

void ldy_f() {
    if (*(pc + 1) == NOP) {
        y = *pc++;
        return;
    }
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    y = *(prg_ram + MAKE_WORD);
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

void rts_f() {
    if (sp == 0xff) {
        stop_cpu();
        return;
    }
    uint8_t low = STACK_POP;
    uint8_t hi = STACK_POP;
    pc = prg_ram + MAKE_WORD;
}

void sbc_f() {}

void sec_f() {}

void sed_f() {}

void sei_f() {}

void sta_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = a;
}

void stx_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = x;
}

void sty_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = y;
}

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
