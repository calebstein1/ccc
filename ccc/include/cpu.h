#ifndef CCC_CPU_H
#define CCC_CPU_H

#include "fixed.h"
#include "opcodes.h"
#include "bitfield.h"

#define CCC_VER "v0.0.4-prealpha"

#define MAKE_WORD (((u16)hi << 8) + low)

#define GET_C (p & 1)
#define GET_Z (p >> 1 & 1)
#define GET_I (p >> 2 & 1)
#define GET_D (p >> 3 & 1)
#define GET_B (p >> 4 & 1)
#define GET_V (p >> 6 & 1)
#define GET_N (p >> 7 & 1)

#define SET_C (p |= S0)
#define SET_Z (p |= S1)
#define SET_I (p |= S2)
#define SET_D (p |= S3)
#define SET_B (p |= S4)
#define SET_V (p |= S6)
#define SET_N (p |= S7)

#define UNSET_C (p &= U0)
#define UNSET_Z (p &= U1)
#define UNSET_I (p &= U2)
#define UNSET_D (p &= U3)
#define UNSET_B (p &= U4)
#define UNSET_V (p &= U6)
#define UNSET_N (p &= U7)

#define STACK_PUSH(v) (*(prg_ram + s-- + 0x100) = v)
#define STACK_POP (*(prg_ram + ++s + 0x100))

#define PC_LOW ((pc - prg_ram) & 0xff)
#define PC_HI ((pc - prg_ram) >> 8)

typedef enum cpu_state {
	CPU_STP,
	BOOT,
	PRG_LD,
	PRG_DBG,
	PRG_RN
} cpu_state;

extern u8 prg_ram[0x10000];
extern u8 *pc;
extern u8 s;
extern u8 a, x, y;
extern u8 p;

extern cpu_state c_state;

void init_ccrom(void);
void *run_cpu(void *arg);
void stop_cpu(void);

#endif /* CCC_CPU_H */
