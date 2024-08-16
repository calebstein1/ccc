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

void anda_f() {}
void andax_f() {}
void anday_f() {}
void andz_f() {}
void andzx_f() {}
void andzy_f() {}
void andi_f() {}

void asla_f() {}
void aslax_f() {}
void aslay_f() {}
void aslz_f() {}
void aslzx_f() {}
void aslzy_f() {}
void aslac_f() {}

void bcc_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bcc65_f() {
    if (!GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void bcs_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bcs65_f() {
    if (GET_C) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void beq_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void beq65_f() {
    if (GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void bit_f() {}

void bmi_f() {
    if (GET_N) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bmi65_f() {
    if (GET_N) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void bne_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bne65_f() {
    if (!GET_Z) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void bpl_f() {
    if (!GET_N) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bpl65_f() {
    if (!GET_N) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void brk_f() {}

void bvc_f() {
    if (!GET_V) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bvc65_f() {
    if (!GET_V) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void bvs_f() {
    if (GET_V) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bvs65_f() {
    if (GET_V) {
        uint8_t low = *pc++;
        pc = prg_ram + PC_HI16 + low;
        return;
    }
    pc++;
}

void clc_f() {
    UNSET_C;
}

void cld_f() {
    UNSET_D;
}

void cli_f() {
    UNSET_I;
}

void clv_f() {
    UNSET_V;
}

void cmpa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    if (a - *(prg_ram + MAKE_WORD)) {
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

void cmpz_f() {
    uint8_t low = *pc++;
    if (a - *(prg_ram + low)) {
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

void cpxz_f() {
    uint8_t low = *pc++;
    if (x - *(prg_ram + low)) {
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

void cpyz_f() {
    uint8_t low = *pc++;
    if (y - *(prg_ram + low)) {
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

void decz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) -= 1;
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

void eora_f() {}
void eorax_f() {}
void eoray_f() {}
void eorz_f() {}
void eorzx_f() {}
void eorzy_f() {}
void eori_f() {}

void inca_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) += 1;
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

void incz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) += 1;
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

void jmpz_f() {
    uint8_t low = *pc++;
    pc = prg_ram + low;
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

void ldaz_f() {
    uint8_t low = *pc++;
    a = *(prg_ram + low);
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

void ldxz_f() {
    uint8_t low = *pc++;
    x = *(prg_ram + low);
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

void ldyz_f() {
    uint8_t low = *pc++;
    y = *(prg_ram + low);
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

void lsra_f() {}
void lsrax_f() {}
void lsray_f() {}
void lsrz_f() {}
void lsrzx_f() {}
void lsrzy_f() {}
void lsrac_f() {}

void nop_f() {}

void oraa_f() {}
void oraax_f() {}
void oraay_f() {}
void oraz_f() {}
void orazx_f() {}
void orazy_f() {}
void orai_f() {}

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

void rola_f() {}
void rolax_f() {}
void rolay_f() {}
void rolz_f() {}
void rolzx_f() {}
void rolzy_f() {}
void rolac_f() {}

void rora_f() {}
void rorax_f() {}
void roray_f() {}
void rorz_f() {}
void rorzx_f() {}
void rorzy_f() {}
void rorac_f() {}

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

void sbca_f() {}
void sbcax_f() {}
void sbcay_f() {}
void sbcz_f() {}
void sbczx_f() {}
void sbczy_f() {}
void sbci_f() {}

void sec_f() {
    SET_C;
}

void sed_f() {
    SET_D;
}

void sei_f() {
    SET_I;
}

void staa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = a;
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

void staz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) = a;
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

void stxz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) = x;
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

void styz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) = y;
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
