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

void anda_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD);
    a &= op;
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

void andax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x);
    a &= op;
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

void anday_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y);
    a &= op;
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

void andz_f() {
    uint8_t low = *pc++;
    uint8_t op = *(prg_ram + low);
    a &= op;
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

void andzx_f() {
    uint8_t low = *pc++;
    uint8_t op = *(prg_ram + low + x);
    a &= op;
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

void andzy_f() {
    uint8_t low = *pc++;
    uint8_t op = *(prg_ram + low + y);
    a &= op;
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

void andi_f() {
    a &= *pc++;
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

void asla_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD;
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void aslax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + x;
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void aslay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + y;
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void aslz_f() {
    uint8_t *op = prg_ram + *pc++;
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void aslzx_f() {
    uint8_t *op = prg_ram + *pc++ + x;
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void aslzy_f() {
    uint8_t *op = prg_ram + *pc++ + y;
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void aslac_f() {
    if (a >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    a <<= 1;
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

void bita_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD;
    if (*op >> 6) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!(a & *op)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void bitax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + x;
    if (*op >> 6) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!(a & *op)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void bitay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + y;
    if (*op >> 6) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!(a & *op)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void bitz_f() {
    uint8_t *op = prg_ram + *pc++;
    if (*op >> 6) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!(a & *op)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void bitzx_f() {
    uint8_t *op = prg_ram + *pc++ + x;
    if (*op >> 6) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!(a & *op)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void bitzy_f() {
    uint8_t *op = prg_ram + *pc++ + y;
    if (*op >> 6) {
        SET_V;
    } else {
        UNSET_V;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!(a & *op)) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

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

void eora_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD);
    a ^= op;
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

void eorax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x);
    a ^= op;
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

void eoray_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y);
    a ^= op;
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

void eorz_f() {
    uint8_t op = *(prg_ram + *pc++);
    a ^= op;
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

void eorzx_f() {
    uint8_t op = *(prg_ram + *pc++ + x);
    a ^= op;
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

void eorzy_f() {
    uint8_t op = *(prg_ram + *pc++ + y);
    a ^= op;
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

void eori_f() {
    a ^= *pc++;
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

void lsra_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD;
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    UNSET_N;
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void lsrax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + x;
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    UNSET_N;
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void lsray_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + y;
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    UNSET_N;
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void lsrz_f() {
    uint8_t *op = prg_ram + *pc++;
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    UNSET_N;
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void lsrzx_f() {
    uint8_t *op = prg_ram + *pc++ + x;
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    UNSET_N;
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void lsrzy_f() {
    uint8_t *op = prg_ram + *pc++ + y;
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    UNSET_N;
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void lsrac_f() {
    if (a & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    a >>= 1;
    UNSET_N;
    if (!a) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void nop_f() {}

void oraa_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD);
    a |= op;
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

void oraax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x);
    a |= op;
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

void oraay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y);
    a |= op;
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

void oraz_f() {
    uint8_t op = *(prg_ram + *pc++);
    a |= op;
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

void orazx_f() {
    uint8_t op = *(prg_ram + *pc++ + x);
    a |= op;
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

void orazy_f() {
    uint8_t op = *(prg_ram + *pc++ + y);
    a |= op;
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

void orai_f() {
    a |= *pc++;
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

void rola_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (c) {
        *op |= 1;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rolax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + x;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (c) {
        *op |= 1;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rolay_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + y;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (c) {
        *op |= 1;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rolz_f() {
    uint8_t *op = prg_ram + *pc++;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (c) {
        *op |= 1;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rolzx_f() {
    uint8_t *op = prg_ram + *pc++ + x;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (c) {
        *op |= 1;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rolzy_f() {
    uint8_t *op = prg_ram + *pc++ + y;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op <<= 1;
    if (c) {
        *op |= 1;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rolac_f() {
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (a >> 7) {
        SET_C;
    } else {
        UNSET_C;
    }
    a <<= 1;
    if (c) {
        a |= 1;
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

void rora_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    if (c) {
        *op |= 128;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rorax_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + x;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    if (c) {
        *op |= 128;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void roray_f() {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t *op = prg_ram + MAKE_WORD + y;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    if (c) {
        *op |= 128;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rorz_f() {
    uint8_t *op = prg_ram + *pc++;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    if (c) {
        *op |= 128;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rorzx_f() {
    uint8_t *op = prg_ram + *pc++ + x;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    if (c) {
        *op |= 128;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rorzy_f() {
    uint8_t *op = prg_ram + *pc++ + y;
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (*op & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    *op >>= 1;
    if (c) {
        *op |= 128;
    }
    if (*op >> 7) {
        SET_N;
    } else {
        UNSET_N;
    }
    if (!*op) {
        SET_Z;
    } else {
        UNSET_Z;
    }
}

void rorac_f() {
    uint8_t c = 0;
    if (GET_C) {
        c = 1;
    }
    if (a & 1) {
        SET_C;
    } else {
        UNSET_C;
    }
    a >>= 1;
    if (c) {
        a |= 128;
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

void sbca_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD) - GET_C;
    a -= op;
    if (a > la) {
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

void sbcax_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + x) - GET_C;
    a -= op;
    if (a > la) {
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

void sbcay_f() {
    uint8_t la = a;
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    uint8_t op = *(prg_ram + MAKE_WORD + y) - GET_C;
    a -= op;
    if (a > la) {
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

void sbcz_f() {
    uint8_t la = a;
    uint8_t op = *(prg_ram + *pc++) - GET_C;
    a -= op;
    if (a > la) {
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

void sbczx_f() {
    uint8_t la = a;
    uint8_t op = *(prg_ram + *pc++ + x) - GET_C;
    a -= op;
    if (a > la) {
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

void sbczy_f() {
    uint8_t la = a;
    uint8_t op = *(prg_ram + *pc++ + y) - GET_C;
    a -= op;
    if (a > la) {
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

void sbci_f() {
    uint8_t la = a;
    uint8_t op = *pc++ - GET_C;
    a -= op;
    if (a > la) {
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
