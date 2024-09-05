#ifndef CCC_CPU_H
#define CCC_CPU_H

#include "fixed.h"
#include "opcodes.h"
#include "bitfield.h"

#define CCC_VER "v0.0.4-prealpha"

/*
 * If bytes 'low' and 'hi' are previously defined in the scope,
 * MAKE_WORD is the 16-bit word created by combining the two bytes
 */
#define MAKE_WORD (((u16)hi << 8) + low)

#define GET_C (p & 1) /* Get the status of the carry flag */
#define GET_Z (p >> 1 & 1) /* Get the status of the zero flag */
#define GET_I (p >> 2 & 1) /* Get the status of the interrupt flag */
#define GET_D (p >> 3 & 1) /* Get the status of the decimal flag */
#define GET_V (p >> 6 & 1) /* Get the status of the overflow flag */
#define GET_N (p >> 7 & 1) /* Get the status of the negative flag */

#define SET_C (p |= S0) /* Set the carry flag */
#define SET_Z (p |= S1) /* Set the zero flag */
#define SET_I (p |= S2) /* Set the interrupt flag */
#define SET_D (p |= S3) /* Set the decimal flag */
#define SET_B (p |= S4) /* Set the break flag */
#define SET_V (p |= S6) /* Set the overflow flag */
#define SET_N (p |= S7) /* Set the negative flag */

#define UNSET_C (p &= U0) /* Clear the carry flag */
#define UNSET_Z (p &= U1) /* Clear the zero flag */
#define UNSET_I (p &= U2) /* Clear the interrupt flag */
#define UNSET_D (p &= U3) /* Clear the decimal flag */
#define UNSET_B (p &= U4) /* Clear the break flag */
#define UNSET_V (p &= U6) /* Clear the overflow flag */
#define UNSET_N (p &= U7) /* Clear the negative flag */

#define STACK_PUSH(v) (write_mem(s-- + 0x100, v)) /* Push the value 'v' to the the stack */
#define STACK_POP (read_mem(++s + 0x100)) /* Pull the next value from the stack */

#define PC_LOW ((pc - get_ptr(0)) & 0xff) /* Get the low byte of the program counter */
#define PC_HI ((pc - get_ptr(0)) >> 8) /* Get the high byte of the program counter */

typedef enum cpu_state {
	CPU_STP,
	BOOT,
	PRG_LD,
	PRG_DBG,
	PRG_RN
} cpu_state;

extern u8 s, a, x, y, p;

extern cpu_state c_state;

void init_ccrom(void);
void *run_cpu(void *arg);
void stop_cpu(void);

#endif /* CCC_CPU_H */
