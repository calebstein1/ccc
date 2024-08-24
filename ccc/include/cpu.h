#ifndef CCC_CPU_H
#define CCC_CPU_H

#include <stdint.h>

#define CCC_VER "v0.0.2-prealpha"
#define OPCODE_COUNT 189

#define MAKE_WORD (((uint16_t)hi << 8) + low)

#define GET_C (p & 1)
#define GET_Z (p >> 1 & 1)
#define GET_I (p >> 2 & 1)
#define GET_D (p >> 3 & 1)
#define GET_B (p >> 4 & 1)
#define GET_V (p >> 6 & 1)
#define GET_N (p >> 7 & 1)

#define SET_C (p |= 0b00000001)
#define SET_Z (p |= 0b00000010)
#define SET_I (p |= 0b00000100)
#define SET_D (p |= 0b00001000)
#define SET_B (p |= 0b00010000)
#define SET_V (p |= 0b01000000)
#define SET_N (p |= 0b10000000)

#define UNSET_C (p &= 0b11111110)
#define UNSET_Z (p &= 0b11111101)
#define UNSET_I (p &= 0b11111011)
#define UNSET_D (p &= 0b11110111)
#define UNSET_B (p &= 0b11101111)
#define UNSET_V (p &= 0b10111111)
#define UNSET_N (p &= 0b01111111)

#define STACK_PUSH(v) (*(prg_ram + s-- + 0x100) = v)
#define STACK_POP (*(prg_ram + ++s + 0x100))

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

void init_ccrom();
void *start_cpu();
void stop_cpu();

#endif //CCC_CPU_H
