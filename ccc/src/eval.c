#include <stdint.h>

#include "globals.h"
#include "opcodes.h"
#include "cpu.h"

void adca_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD) + GET_C;
    a += op;
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
    if ((la >> 7 == op >> 7 && la >> 7 != a >> 7)) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void adcz_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t op = *(prg_ram + low) + GET_C;
    a += op;
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
    if ((la >> 7 == op >> 7 && la >> 7 != a >> 7)) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void adcax_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x) + GET_C;
    a += op;
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
    if ((la >> 7 == op >> 7 && la >> 7 != a >> 7)) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void adcay_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y) + GET_C;
    a += op;
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
    if ((la >> 7 == op >> 7 && la >> 7 != a >> 7)) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void adczx_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t op = *(prg_ram + low + x) + GET_C;
    a += op;
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
    if ((la >> 7 == op >> 7 && la >> 7 != a >> 7)) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void adczy_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t op = *(prg_ram + low + y) + GET_C;
    a += op;
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
    if ((la >> 7 == op >> 7 && la >> 7 != a >> 7)) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void adci_f() {
    uint8_t la = a;
    uint8_t op = *pc++ + GET_C;
    a += op;
    if (a < la) {
        SET_C;
    } else {
        UNSET_C;
    }
    if ((la >> 7 == op >> 7 && la >> 7 != a >> 7)) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void and_f() {}

void asl_f() {}

void bcca_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bccz_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + low;
        return;
    }
    pc++;
}

void bccax_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + x;
        return;
    }
    pc += 2;
}

void bccay_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + y;
        return;
    }
    pc += 2;
}

void bcczx_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + low + x;
        return;
    }
    pc++;
}

void bcczy_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + low + y;
        return;
    }
    pc++;
}

void bcsa_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bcsz_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + low;
        return;
    }
    pc++;
}

void bcsax_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + x;
        return;
    }
    pc += 2;
}

void bcsay_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + y;
        return;
    }
    pc += 2;
}

void bcszx_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + low + x;
        return;
    }
    pc++;
}

void bcszy_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + low + y;
        return;
    }
    pc++;
}

void beqa_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void beqz_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + low;
        return;
    }
    pc++;
}

void beqax_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + x;
        return;
    }
    pc += 2;
}

void beqay_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + y;
        return;
    }
    pc += 2;
}

void beqzx_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + low + x;
        return;
    }
    pc++;
}

void beqzy_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + low + y;
        return;
    }
    pc++;
}

void bit_f() {}

void bmi_f() {}

void bnea_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bnez_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + low;
        return;
    }
    pc++;
}

void bneax_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + x;
        return;
    }
    pc += 2;
}

void bneay_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD + y;
        return;
    }
    pc += 2;
}

void bnezx_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + low + x;
        return;
    }
    pc++;
}

void bnezy_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + low + y;
        return;
    }
    pc++;
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

void cmpa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (a - *(prg_ram + MAKE_WORD)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cmpz_f() {
    uint8_t low = *pc++;
    if (a - *(prg_ram + low)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cmpax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (a - *(prg_ram + MAKE_WORD + x)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cmpay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (a - *(prg_ram + MAKE_WORD + y)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cmpzx_f() {
    uint8_t low = *pc++;
    if (a - *(prg_ram + low + x)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cmpzy_f() {
    uint8_t low = *pc++;
    if (a - *(prg_ram + low + y)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cmpi_f() {
    if (a - *pc++) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpxa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (x - *(prg_ram + MAKE_WORD)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpxz_f() {
    uint8_t low = *pc++;
    if (x - *(prg_ram + low)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpxax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (x - *(prg_ram + MAKE_WORD + x)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpxay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (x - *(prg_ram + MAKE_WORD + y)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpxzx_f() {
    uint8_t low = *pc++;
    if (x - *(prg_ram + low + x)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpxzy_f() {
    uint8_t low = *pc++;
    if (x - *(prg_ram + low + y)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpxi_f() {
    if (x - *pc++) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpya_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (y - *(prg_ram + MAKE_WORD)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpyz_f() {
    uint8_t low = *pc++;
    if (y - *(prg_ram + low)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpyax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (y - *(prg_ram + MAKE_WORD + x)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpyay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (y - *(prg_ram + MAKE_WORD + y)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpyzx_f() {
    uint8_t low = *pc++;
    if (y - *(prg_ram + low + x)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpyzy_f() {
    uint8_t low = *pc++;
    if (y - *(prg_ram + low + y)) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void cpyi_f() {
    if (y - *pc++) {
        UNSET_Z;
        return;
    }
    SET_Z;
}

void deca_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) -= 1;
}

void decz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) -= 1;
}

void decax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) -= 1;
}

void decay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) -= 1;
}

void deczx_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + x) -= 1;
}

void deczy_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + y) -= 1;
}

void dex_f() {
    x--;
}

void dey_f() {
    y--;
}

void for_f() {}

void inca_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) += 1;
}

void incz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) += 1;
}

void incax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) += 1;
}

void incay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) += 1;
}

void inczx_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + x) += 1;
}

void inczy_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + y) += 1;
}

void inx_f() {
    x++;
}

void iny_f() {
    y++;
}

void jmpa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    pc = prg_ram + MAKE_WORD;
}

void jmpz_f() {
    uint8_t low = *pc++;
    pc = prg_ram + low;
}

void jmpax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    pc = prg_ram + MAKE_WORD + x;
}

void jmpay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    pc = prg_ram + MAKE_WORD + y;
}

void jmpzx_f() {
    uint8_t low = *pc++;
    pc = prg_ram + low + x;
}

void jmpzy_f() {
    uint8_t low = *pc++;
    pc = prg_ram + low + y;
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

void ldaa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    a = *(prg_ram + MAKE_WORD);
}

void ldaz_f() {
    uint8_t low = *pc++;
    a = *(prg_ram + low);
}

void ldaax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    a = *(prg_ram + MAKE_WORD + x);
}

void ldaay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    a = *(prg_ram + MAKE_WORD + y);
}

void ldazx_f() {
    uint8_t low = *pc++;
    a = *(prg_ram + low + x);
}

void ldazy_f() {
    uint8_t low = *pc++;
    a = *(prg_ram + low + y);
}

void ldai_f() {
    a = *pc++;
}

void ldxa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    x = *(prg_ram + MAKE_WORD);
}

void ldxz_f() {
    uint8_t low = *pc++;
    x = *(prg_ram + low);
}

void ldxax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    x = *(prg_ram + MAKE_WORD + x);
}

void ldxay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    x = *(prg_ram + MAKE_WORD + y);
}

void ldxzx_f() {
    uint8_t low = *pc++;
    x = *(prg_ram + low + x);
}

void ldxzy_f() {
    uint8_t low = *pc++;
    x = *(prg_ram + low + y);
}

void ldxi_f() {
    x = *pc++;
}

void ldya_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    y = *(prg_ram + MAKE_WORD);
}

void ldyz_f() {
    uint8_t low = *pc++;
    y = *(prg_ram + low);
}

void ldyax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    y = *(prg_ram + MAKE_WORD + x);
}

void ldyay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    y = *(prg_ram + MAKE_WORD + y);
}

void ldyzx_f() {
    uint8_t low = *pc++;
    y = *(prg_ram + low + x);
}

void ldyzy_f() {
    uint8_t low = *pc++;
    y = *(prg_ram + low + y);
}

void ldyi_f() {
    y = *pc++;
}

void lsr_f() {}

void nop_f() {}

void ora_f() {}

void pha_f() {
    STACK_PUSH(a);
}

void php_f() {
    STACK_PUSH(p);
}

void pla_f() {
    a = STACK_POP;
}

void plp_f() {
    p = STACK_POP;
}

void rol_f() {}

void ror_f() {}

void rti_f() {}

void rts_f() {
    if (s == 0xff) {
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

void staa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = a;
}

void staz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) = a;
}

void staax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) = a;
}

void staay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) = a;
}

void stazx_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + x) = a;
}

void stazy_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + y) = a;
}

void stxa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = x;
}

void stxz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) = x;
}

void stxax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) = x;
}

void stxay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) = x;
}

void stxzx_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + x) = x;
}

void stxzy_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + y) = x;
}

void stya_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = y;
}

void styz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) = y;
}

void styax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) = y;
}

void styay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) = y;
}

void styzx_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + x) = y;
}

void styzy_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + y) = y;
}

void tax_f() {
    x = a;
}

void tay_f() {
    y = a;
}

void tsx_f() {
    x = s;
}

void txa_f() {
    a = x;
}

void txs_f() {
    s = x;
}

void tya_f() {
    a = y;
}

void (*eval_func[OPCODE_COUNT])() = {
#define X(opcode, op_fn, ...) op_fn,
        OPCODES_LIST
#undef X
};
