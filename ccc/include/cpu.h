#ifndef CCC_CPU_H
#define CCC_CPU_H

#include <stdint.h>

#define CCC_VER "0.0.1-prealpha"
#define OPCODE_COUNT 189

#define MAKE_WORD (((uint16_t)hi << 8) + low)

#define GET_C (p & 1)
#define GET_Z (p >> 1 & 1)
#define GET_I (p >> 2 & 1)
#define GET_D (p >> 3 & 1)
#define GET_B (p >> 4 & 1)
#define GET_V (p >> 6 & 1)
#define GET_N (p >> 7 & 1)

#define SET_C (p |= 1)
#define SET_Z (p |= 2)
#define SET_I (p |= 4)
#define SET_D (p |= 8)
#define SET_B (p |= 16)
#define SET_V (p |= 64)
#define SET_N (p |= 128)

#define UNSET_C (p &= 254)
#define UNSET_Z (p &= 253)
#define UNSET_I (p &= 251)
#define UNSET_D (p &= 247)
#define UNSET_B (p &= 239)
#define UNSET_V (p &= 191)
#define UNSET_N (p &= 127)

#define STACK_PUSH(v) (*(prg_ram + s-- + 256) = v)
#define STACK_POP (*(prg_ram + ++s + 256))

#define PC_LOW ((pc - prg_ram) & 0xff)
#define PC_HI ((pc - prg_ram) >> 8)

typedef enum cpu_state {
    CPU_STP,
    BOOT,
    PRG_LD,
    PRG_DBG,
    PRG_RN,
} cpu_state;

extern uint8_t prg_ram[0x10000];
extern uint8_t *pc;
extern uint8_t s;
extern uint8_t a, x, y;
extern uint8_t p;

extern cpu_state c_state;

extern void (*eval_func[OPCODE_COUNT])();

void *start_cpu();
void stop_cpu();

#endif //CCC_CPU_H
