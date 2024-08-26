#include <stdint.h>

#include "opcodes.h"
#include "cpu.h"

void adca_f(void) {
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

void adcax_f(void) {
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

void adcay_f(void) {
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

void adcz_f(void) {
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

void adczx_f(void) {
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

void adczy_f(void) {
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

void adci_f(void) {
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

void anda_f(void) {
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

void andax_f(void) {
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

void anday_f(void) {
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

void andz_f(void) {
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

void andzx_f(void) {
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

void andzy_f(void) {
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

void andi_f(void) {
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

void asla_f(void) {
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

void aslax_f(void) {
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

void aslay_f(void) {
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

void aslz_f(void) {
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

void aslzx_f(void) {
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

void aslzy_f(void) {
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

void aslac_f(void) {
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

void bcc_f(void) {
    if (!GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bcc65_f(void) {
    if (!GET_C) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void bcs_f(void) {
    if (GET_C) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bcs65_f(void) {
    if (GET_C) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void beq_f(void) {
    if (GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void beq65_f(void) {
    if (GET_Z) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void bita_f(void) {
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

void bitax_f(void) {
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

void bitay_f(void) {
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

void bitz_f(void) {
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

void bitzx_f(void) {
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

void bitzy_f(void) {
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

void bmi_f(void) {
    if (GET_N) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bmi65_f(void) {
    if (GET_N) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void bne_f(void) {
    if (!GET_Z) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bne65_f(void) {
    if (!GET_Z) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void bpl_f(void) {
    if (!GET_N) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bpl65_f(void) {
    if (!GET_N) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void brk_f(void) {
    SET_I;
    SET_B;
    uint8_t low = PC_LOW;
    uint8_t hi = PC_HI;
    if (!low) {
        hi++;
    }
    STACK_PUSH(hi);
    STACK_PUSH(low);
    STACK_PUSH(p);
    low = prg_ram[0xfffe];
    hi = prg_ram[0xffff];
    pc = prg_ram + MAKE_WORD;
}

void bvc_f(void) {
    if (!GET_V) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bvc65_f(void) {
    if (!GET_V) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void bvs_f(void) {
    if (GET_V) {
        uint8_t low = *pc++;
        uint8_t hi = *pc++;
        pc = prg_ram + MAKE_WORD;
        return;
    }
    pc += 2;
}

void bvs65_f(void) {
    if (GET_V) {
        int8_t off = (int8_t)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void clc_f(void) {
    UNSET_C;
}

void cld_f(void) {
    UNSET_D;
}

void cli_f(void) {
    UNSET_I;
}

void clv_f(void) {
    UNSET_V;
}

void cmpa_f(void) {
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

void cmpax_f(void) {
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

void cmpay_f(void) {
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

void cmpz_f(void) {
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

void cmpzx_f(void) {
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

void cmpzy_f(void) {
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

void cmpi_f(void) {
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

void cpxa_f(void) {
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

void cpxax_f(void) {
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

void cpxay_f(void) {
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

void cpxz_f(void) {
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

void cpxzx_f(void) {
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

void cpxzy_f(void) {
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

void cpxi_f(void) {
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

void cpya_f(void) {
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

void cpyax_f(void) {
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

void cpyay_f(void) {
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

void cpyz_f(void) {
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

void cpyzx_f(void) {
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

void cpyzy_f(void) {
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

void cpyi_f(void) {
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

void deca_f(void) {
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

void decax_f(void) {
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

void decay_f(void) {
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

void decz_f(void) {
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

void deczx_f(void) {
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

void deczy_f(void) {
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

void dex_f(void) {
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

void dey_f(void) {
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

void eora_f(void) {
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

void eorax_f(void) {
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

void eoray_f(void) {
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

void eorz_f(void) {
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

void eorzx_f(void) {
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

void eorzy_f(void) {
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

void eori_f(void) {
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

void inca_f(void) {
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

void incax_f(void) {
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

void incay_f(void) {
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

void incz_f(void) {
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

void inczx_f(void) {
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

void inczy_f(void) {
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

void inx_f(void) {
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

void iny_f(void) {
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

void jmpa_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    pc = prg_ram + MAKE_WORD;
}

void jmpax_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    pc = prg_ram + MAKE_WORD + x;
}

void jmpay_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    pc = prg_ram + MAKE_WORD + y;
}

void jmpz_f(void) {
    uint8_t low = *pc++;
    pc = prg_ram + low;
}

void jmpzx_f(void) {
    uint8_t low = *pc++;
    pc = prg_ram + low + x;
}

void jmpzy_f(void) {
    uint8_t low = *pc++;
    pc = prg_ram + low + y;
}

void jsr_f(void) {
    uint8_t low = PC_LOW + 1;
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

void ldaa_f(void) {
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

void ldaax_f(void) {
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

void ldaay_f(void) {
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

void ldaz_f(void) {
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

void ldazx_f(void) {
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

void ldazy_f(void) {
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

void ldai_f(void) {
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

void ldxa_f(void) {
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

void ldxax_f(void) {
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

void ldxay_f(void) {
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

void ldxz_f(void) {
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

void ldxzx_f(void) {
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

void ldxzy_f(void) {
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

void ldxi_f(void) {
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

void ldya_f(void) {
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

void ldyax_f(void) {
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

void ldyay_f(void) {
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

void ldyz_f(void) {
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

void ldyzx_f(void) {
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

void ldyzy_f(void) {
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

void ldyi_f(void) {
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

void lsra_f(void) {
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

void lsrax_f(void) {
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

void lsray_f(void) {
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

void lsrz_f(void) {
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

void lsrzx_f(void) {
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

void lsrzy_f(void) {
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

void lsrac_f(void) {
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

void nop_f(void) {}

void oraa_f(void) {
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

void oraax_f(void) {
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

void oraay_f(void) {
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

void oraz_f(void) {
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

void orazx_f(void) {
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

void orazy_f(void) {
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

void orai_f(void) {
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

void pha_f(void) {
    STACK_PUSH(a);
}

void php_f(void) {
    SET_B;
    STACK_PUSH(p);
}

void pla_f(void) {
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

void plp_f(void) {
    p = STACK_POP;
    UNSET_I;
    UNSET_B;
}

void rola_f(void) {
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

void rolax_f(void) {
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

void rolay_f(void) {
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

void rolz_f(void) {
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

void rolzx_f(void) {
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

void rolzy_f(void) {
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

void rolac_f(void) {
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

void rora_f(void) {
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

void rorax_f(void) {
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

void roray_f(void) {
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

void rorz_f(void) {
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

void rorzx_f(void) {
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

void rorzy_f(void) {
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

void rorac_f(void) {
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

void rti_f(void) {
    p = STACK_POP;
    UNSET_I;
    UNSET_B;
    uint8_t low = STACK_POP;
    uint8_t hi = STACK_POP;
    pc = prg_ram + MAKE_WORD;
}

void rts_f(void) {
    if (s == 0xff) {
        stop_cpu();
        return;
    }
    uint8_t low = STACK_POP;
    uint8_t hi = STACK_POP;
    pc = prg_ram + MAKE_WORD + 1;
}

void sbca_f(void) {
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

void sbcax_f(void) {
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

void sbcay_f(void) {
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

void sbcz_f(void) {
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

void sbczx_f(void) {
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

void sbczy_f(void) {
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

void sbci_f(void) {
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

void sec_f(void) {
    SET_C;
}

void sed_f(void) {
    SET_D;
}

void sei_f(void) {
    SET_I;
}

void staa_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = a;
}

void staax_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) = a;
}

void staay_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) = a;
}

void staz_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low) = a;
}

void stazx_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low + x) = a;
}

void stazy_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low + y) = a;
}

void stxa_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = x;
}

void stxax_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) = x;
}

void stxay_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) = x;
}

void stxz_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low) = x;
}

void stxzx_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low + x) = x;
}

void stxzy_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low + y) = x;
}

void stya_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD) = y;
}

void styax_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + x) = y;
}

void styay_f(void) {
    uint8_t low = *pc++;
    uint8_t hi = *pc++;
    *(prg_ram + MAKE_WORD + y) = y;
}

void styz_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low) = y;
}

void styzx_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low + x) = y;
}

void styzy_f(void) {
    uint8_t low = *pc++;
    *(prg_ram + low + y) = y;
}

void tax_f(void) {
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

void tay_f(void) {
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

void tsx_f(void) {
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

void txa_f(void) {
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

void txs_f(void) {
    s = x;
}

void tya_f(void) {
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

void (*eval_func[OPCODE_COUNT])(void) = {
#define X(opcode, op_fn, ...) op_fn,
        OPCODES_LIST
#undef X
};
