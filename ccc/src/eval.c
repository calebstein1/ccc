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
        int8_t off = (int8_t)*pc++;
        pc += off;
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
        int8_t off = (int8_t)*pc++;
        pc += off;
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
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void bita_f() {}
void bitax_f() {}
void bitay_f() {}
void bitz_f() {}
void bitzx_f() {}
void bitzy_f() {}

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
        int8_t off = (int8_t)*pc++;
        pc += off;
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
        int8_t off = (int8_t)*pc++;
        pc += off;
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
        int8_t off = (int8_t)*pc++;
        pc += off;
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
        int8_t off = (int8_t)*pc++;
        pc += off;
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
        int8_t off = (int8_t)*pc++;
        pc += off;
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
    uint8_t op = *(prg_ram + MAKE_WORD);
    if (a - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((a - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cmpax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x);
    if (a - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((a - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cmpay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y);
    if (a - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((a - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cmpz_f() {
    uint8_t op = *(prg_ram + *pc++);
    if (a - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((a - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cmpzx_f() {
    uint8_t op = *(prg_ram + *pc++ + x);
    if (a - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((a - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cmpzy_f() {
    uint8_t op = *(prg_ram + *pc++ + y);
    if (a - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((a - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cmpi_f() {
    uint8_t op = *pc++;
    if (a - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((a - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpxa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD);
    if (x - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((x - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpxax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x);
    if (x - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((x - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpxay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y);
    if (x - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((x - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpxz_f() {
    uint8_t op = *(prg_ram + *pc++);
    if (x - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((x - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpxzx_f() {
    uint8_t op = *(prg_ram + *pc++ + x);
    if (x - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((x - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpxzy_f() {
    uint8_t op = *(prg_ram + *pc++ + y);
    if (x - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((x - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpxi_f() {
    uint8_t op = *pc++;
    if (x - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((x - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpya_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD);
    if (y - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((y - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpyax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x);
    if (y - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((y - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpyay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y);
    if (y - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((y - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpyz_f() {
    uint8_t op = *(prg_ram + *pc++);
    if (y - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((y - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpyzx_f() {
    uint8_t op = *(prg_ram + *pc++ + x);
    if (y - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((y - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpyzy_f() {
    uint8_t low = *pc++;
    uint8_t op = *(prg_ram + *pc++ + y);
    if (y - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((y - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void cpyi_f() {
    uint8_t op = *pc++;
    if (y - op) {
        UNSET_Z;
    } else {
        SET_Z;
    }
    if ((y - op) >> 7) {
        SET_N;
        SET_C;
    } else {
        UNSET_N;
        UNSET_C;
    }
}

void deca_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) -= 1;
    if (!*(prg_ram + MAKE_WORD)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + MAKE_WORD) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void decax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) -= 1;
    if (!*(prg_ram + MAKE_WORD + x)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + MAKE_WORD + x) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void decay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) -= 1;
    if (!*(prg_ram + MAKE_WORD + y)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + MAKE_WORD + y) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void decz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) -= 1;
    if (!*(prg_ram + low)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + low) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void deczx_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + x) -= 1;
    if (!*(prg_ram + low + x)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + low + x) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void deczy_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + y) -= 1;
    if (!*(prg_ram + low + y)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + low + y) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void dex_f() {
    x--;
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void dey_f() {
    y--;
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
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
    if (!*(prg_ram + MAKE_WORD)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + MAKE_WORD) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void incax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) += 1;
    if (!*(prg_ram + MAKE_WORD + x)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + MAKE_WORD + x) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void incay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) += 1;
    if (!*(prg_ram + MAKE_WORD + y)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + MAKE_WORD + y) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void incz_f() {
    uint8_t low = *pc++;
    *(prg_ram + low) += 1;
    if (!*(prg_ram + low)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + low) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void inczx_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + x) += 1;
    if (!*(prg_ram + low + x)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + low + x) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void inczy_f() {
    uint8_t low = *pc++;
    *(prg_ram + low + y) += 1;
    if (!*(prg_ram + low + y)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (*(prg_ram + low + y) >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void inx_f() {
    x++;
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void iny_f() {
    y++;
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
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
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldaax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    a = *(prg_ram + MAKE_WORD + x);
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldaay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    a = *(prg_ram + MAKE_WORD + y);
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldaz_f() {
    uint8_t low = *pc++;
    a = *(prg_ram + low);
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldazx_f() {
    uint8_t low = *pc++;
    a = *(prg_ram + low + x);
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldazy_f() {
    uint8_t low = *pc++;
    a = *(prg_ram + low + y);
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldai_f() {
    a = *pc++;
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldxa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    x = *(prg_ram + MAKE_WORD);
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldxax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    x = *(prg_ram + MAKE_WORD + x);
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldxay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    x = *(prg_ram + MAKE_WORD + y);
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldxz_f() {
    uint8_t low = *pc++;
    x = *(prg_ram + low);
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldxzx_f() {
    uint8_t low = *pc++;
    x = *(prg_ram + low + x);
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldxzy_f() {
    uint8_t low = *pc++;
    x = *(prg_ram + low + y);
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldxi_f() {
    x = *pc++;
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldya_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    y = *(prg_ram + MAKE_WORD);
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldyax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    y = *(prg_ram + MAKE_WORD + x);
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldyay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    y = *(prg_ram + MAKE_WORD + y);
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldyz_f() {
    uint8_t low = *pc++;
    y = *(prg_ram + low);
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldyzx_f() {
    uint8_t low = *pc++;
    y = *(prg_ram + low + x);
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldyzy_f() {
    uint8_t low = *pc++;
    y = *(prg_ram + low + y);
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void ldyi_f() {
    y = *pc++;
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
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
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
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
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void tay_f() {
    y = a;
    if (!y) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (y >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void tsx_f() {
    x = s;
    if (!x) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (x >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void txa_f() {
    a = x;
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void txs_f() {
    s = x;
}

void tya_f() {
    a = y;
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
    if (a >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
}

void (*eval_func[OPCODE_COUNT])() = {
#define X(opcode, op_fn, ...) op_fn,
        OPCODES_LIST
#undef X
};
