#include "fixed.h"
#include "cpu.h"

/* FUnction prototypes */
#define X(opcode, op_fn, str_lit) void op_fn(void);
        OPCODES_LIST
#undef X

/* Jump table */
void (*eval_func[OPCODE_COUNT])(void) = {
#define X(opcode, op_fn, str_lit) op_fn,
        OPCODES_LIST
#undef X
};

/*
 * Evaluator functions
 */
void
adca_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD) + GET_C;
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

void
adcax_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + x) + GET_C;
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

void
adcay_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + y) + GET_C;
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

void
adcz_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 op = *(prg_ram + low) + GET_C;
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

void
adczx_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 op = *(prg_ram + low + x) + GET_C;
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

void
adci_f(void) {
    u8 la = a;
    u8 op = *pc++ + GET_C;
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

void
anda_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD);
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

void
andax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + x);
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

void
anday_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + y);
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

void
andz_f(void) {
    u8 low = *pc++;
    u8 op = *(prg_ram + low);
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

void
andzx_f(void) {
    u8 low = *pc++;
    u8 op = *(prg_ram + low + x);
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

void
andi_f(void) {
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

void
asla_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD;
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

void
aslax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD + x;
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

void
aslz_f(void) {
    u8 *op = prg_ram + *pc++;
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

void
aslzx_f(void) {
    u8 *op = prg_ram + *pc++ + x;
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

void
aslac_f(void) {
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

void
bcc_f(void) {
    if (!GET_C) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
bcs_f(void) {
    if (GET_C) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
beq_f(void) {
    if (GET_Z) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
bita_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD;
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

void
bitz_f(void) {
    u8 *op = prg_ram + *pc++;
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

void
bmi_f(void) {
    if (GET_N) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
bne_f(void) {
    if (!GET_Z) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
bpl_f(void) {
    if (!GET_N) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
brk_f(void) {
    u8 low = PC_LOW;
    u8 hi = PC_HI;
    SET_I;
    SET_B;
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

void
bvc_f(void) {
    if (!GET_V) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
bvs_f(void) {
    if (GET_V) {
        s8 off = (s8)*pc++;
        pc += off;
        return;
    }
    pc++;
}

void
clc_f(void) {
    UNSET_C;
}

void
cld_f(void) {
    UNSET_D;
}

void
cli_f(void) {
    UNSET_I;
}

void
clv_f(void) {
    UNSET_V;
}

void
cmpa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD);
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

void
cmpax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + x);
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

void
cmpay_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + y);
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

void
cmpz_f(void) {
    u8 op = *(prg_ram + *pc++);
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

void
cmpzx_f(void) {
    u8 op = *(prg_ram + *pc++ + x);
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

void
cmpi_f(void) {
    u8 op = *pc++;
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

void
cpxa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD);
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

void
cpxz_f(void) {
    u8 op = *(prg_ram + *pc++);
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

void
cpxi_f(void) {
    u8 op = *pc++;
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

void
cpya_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD);
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

void
cpyz_f(void) {
    u8 op = *(prg_ram + *pc++);
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

void
cpyi_f(void) {
    u8 op = *pc++;
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

void
deca_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
decax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
decz_f(void) {
    u8 low = *pc++;
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

void
deczx_f(void) {
    u8 low = *pc++;
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

void
dex_f(void) {
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

void
dey_f(void) {
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

void
eora_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD);
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

void
eorax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + x);
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

void
eoray_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + y);
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

void
eorz_f(void) {
    u8 op = *(prg_ram + *pc++);
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

void
eorzx_f(void) {
    u8 op = *(prg_ram + *pc++ + x);
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

void
eori_f(void) {
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

void
inca_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
incax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
incz_f(void) {
    u8 low = *pc++;
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

void
inczx_f(void) {
    u8 low = *pc++;
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

void
inx_f(void) {
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

void
iny_f(void) {
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

void
jmpa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    pc = prg_ram + MAKE_WORD;
}

void
jsr_f(void) {
    u8 low = PC_LOW + 1;
    u8 hi = PC_HI;
    if (low <= 1) {
        hi++;
    }
    STACK_PUSH(hi);
    STACK_PUSH(low);

    low = *pc++;
    hi = *pc++;
    pc = prg_ram + MAKE_WORD;
}

void
ldaa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
ldaax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
ldaay_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
ldaz_f(void) {
    u8 low = *pc++;
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

void
ldazx_f(void) {
    u8 low = *pc++;
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

void
ldai_f(void) {
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

void
ldxa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
ldxay_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
ldxz_f(void) {
    u8 low = *pc++;
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

void
ldxzy_f(void) {
    u8 low = *pc++;
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

void
ldxi_f(void) {
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

void
ldya_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
ldyax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
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

void
ldyz_f(void) {
    u8 low = *pc++;
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

void
ldyzx_f(void) {
    u8 low = *pc++;
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

void
ldyi_f(void) {
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

void
lsra_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD;
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

void
lsrax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD + x;
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

void
lsrz_f(void) {
    u8 *op = prg_ram + *pc++;
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

void
lsrzx_f(void) {
    u8 *op = prg_ram + *pc++ + x;
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

void
lsrac_f(void) {
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

void
nop_f(void) {}

void
oraa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD);
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

void
oraax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + x);
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

void
oraay_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + y);
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

void
oraz_f(void) {
    u8 op = *(prg_ram + *pc++);
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

void
orazx_f(void) {
    u8 op = *(prg_ram + *pc++ + x);
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

void
orai_f(void) {
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

void
pha_f(void) {
    STACK_PUSH(a);
}

void
php_f(void) {
    SET_B;
    STACK_PUSH(p);
}

void
pla_f(void) {
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

void
plp_f(void) {
    p = STACK_POP;
    UNSET_I;
    UNSET_B;
}

void
rola_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD;
    u8 c = 0;
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

void
rolax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD + x;
    u8 c = 0;
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

void
rolz_f(void) {
    u8 *op = prg_ram + *pc++;
    u8 c = 0;
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

void
rolzx_f(void) {
    u8 *op = prg_ram + *pc++ + x;
    u8 c = 0;
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

void
rolac_f(void) {
    u8 c = 0;
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

void
rora_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD;
    u8 c = 0;
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

void
rorax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 *op = prg_ram + MAKE_WORD + x;
    u8 c = 0;
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

void
rorz_f(void) {
    u8 *op = prg_ram + *pc++;
    u8 c = 0;
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

void
rorzx_f(void) {
    u8 *op = prg_ram + *pc++ + x;
    u8 c = 0;
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

void
rorac_f(void) {
    u8 c = 0;
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

void
rti_f(void) {
    u8 low;
    u8 hi;

    p = STACK_POP;
    low = STACK_POP;
    hi = STACK_POP;
    UNSET_I;
    UNSET_B;
    pc = prg_ram + MAKE_WORD;
}

void
rts_f(void) {
    u8 low;
    u8 hi;

    if (s == 0xff) {
        stop_cpu();
        return;
    }
    low = STACK_POP;
    hi = STACK_POP;
    pc = prg_ram + MAKE_WORD + 1;
}

void
sbca_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD) - GET_C;
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

void
sbcax_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + x) - GET_C;
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

void
sbcay_f(void) {
    u8 la = a;
    u8 low = *pc++;
    u8 hi = *pc++;
    u8 op = *(prg_ram + MAKE_WORD + y) - GET_C;
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

void
sbcz_f(void) {
    u8 la = a;
    u8 op = *(prg_ram + *pc++) - GET_C;
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

void
sbczx_f(void) {
    u8 la = a;
    u8 op = *(prg_ram + *pc++ + x) - GET_C;
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

void
sbci_f(void) {
    u8 la = a;
    u8 op = *pc++ - GET_C;
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

void
sec_f(void) {
    SET_C;
}

void
sed_f(void) {
    SET_D;
}

void
sei_f(void) {
    SET_I;
}

void
staa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    *(prg_ram + MAKE_WORD) = a;
}

void
staax_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    *(prg_ram + MAKE_WORD + x) = a;
}

void
staay_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    *(prg_ram + MAKE_WORD + y) = a;
}

void
staz_f(void) {
    u8 low = *pc++;
    *(prg_ram + low) = a;
}

void
stazx_f(void) {
    u8 low = *pc++;
    *(prg_ram + low + x) = a;
}

void
stxa_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    *(prg_ram + MAKE_WORD) = x;
}

void
stxz_f(void) {
    u8 low = *pc++;
    *(prg_ram + low) = x;
}

void
stxzy_f(void) {
    u8 low = *pc++;
    *(prg_ram + low + y) = x;
}

void
stya_f(void) {
    u8 low = *pc++;
    u8 hi = *pc++;
    *(prg_ram + MAKE_WORD) = y;
}

void
styz_f(void) {
    u8 low = *pc++;
    *(prg_ram + low) = y;
}

void
styzx_f(void) {
    u8 low = *pc++;
    *(prg_ram + low + x) = y;
}

void
tax_f(void) {
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

void
tay_f(void) {
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

void
tsx_f(void) {
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

void
txa_f(void) {
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

void
txs_f(void) {
    s = x;
}

void
tya_f(void) {
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
