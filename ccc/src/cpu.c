#include <stdio.h>

/* Posix Headers */
#include <sys/time.h>

#include "fixed.h"
#include "console.h"
#include "shell.h"
#include "display.h"
#include "eval.h"
#include "memory.h"
#include "cpu.h"

/* CPU Registers, Stack Pointer */
u8 a, x, y;
u8 s = 0xff;
u8 p = 0x20;

cpu_state c_state = BOOT;

void*
run_cpu(void *arg) {
	const opcode_e t6502[] = {
		BRK, NOP, NOP, NOP, NOP, ORA_Z, ASL_Z, NOP, PHP, ORA_I, ASL_AC, NOP, NOP, ORA_A, ASL_A, NOP,
		BPL, NOP, NOP, NOP, NOP, ORA_ZX, ASL_ZX, NOP, CLC, ORA_AY, NOP, NOP, NOP, ORA_AX, ASL_AX, NOP,
		JSR, NOP, NOP, NOP,  BIT_Z, AND_Z, ROL_Z, NOP, PLP, AND_I, ROL_AC, NOP, BIT_A, AND_A, ROL_A, NOP,
		BMI, NOP, NOP, NOP, NOP, AND_ZX, ROL_ZX, NOP, SEC, AND_AY, NOP, NOP, NOP, AND_AX, ROL_AX, NOP,
		RTI, NOP, NOP, NOP, NOP, EOR_Z, LSR_Z, NOP, PHA, EOR_I, LSR_AC, NOP, JMP_A, EOR_A, LSR_A, NOP,
		BVC, NOP, NOP, NOP, NOP, EOR_ZX, LSR_ZX, NOP, CLI, EOR_AY, NOP, NOP, NOP, EOR_AX, LSR_AX, NOP,
		RTS, NOP, NOP, NOP, NOP, ADC_Z, ROR_Z, NOP, PLA, ADC_I, ROR_AC, NOP, NOP, ADC_A, ROR_A, NOP,
		BVS, NOP, NOP, NOP, NOP, ADC_ZX, ROR_ZX, NOP, SEI, ADC_AY, NOP, NOP, NOP, ADC_AX, ROR_AX, NOP,
		NOP, NOP, NOP, NOP, STY_Z, STA_Z, STX_Z, NOP, DEY, NOP, TXA, NOP, STY_A, STA_A, STX_A, NOP,
		BCC, NOP, NOP, NOP, STY_ZX, STA_ZX, STX_ZY, NOP, TYA, STA_AY, TXS, NOP, NOP, STA_AX, NOP, NOP,
		LDY_I, NOP, LDX_I, NOP, LDY_Z, LDA_Z, LDX_Z, NOP, TAY, LDA_I, TAX, NOP, LDY_A, LDA_A, LDX_A, NOP,
		BCS, NOP, NOP, NOP, LDY_ZX, LDA_ZX, LDX_ZY, NOP, CLV, LDA_AY, TSX, NOP, LDY_AX, LDA_AX, LDX_AY, NOP,
		CPY_I, NOP, NOP, NOP, CPY_Z, CMP_Z, DEC_Z, NOP, INY, CMP_I, DEX, NOP, CPY_A, CMP_A, DEC_A, NOP,
		BNE, NOP, NOP, NOP, NOP, CMP_ZX, DEC_ZX, NOP, CLD, CMP_AY, NOP, NOP, NOP, CMP_AX, DEC_AX, NOP,
		CPX_I, NOP, NOP, NOP, CPX_Z, SBC_Z, INC_Z, NOP, INX, SBC_I, NOP, NOP, CPX_A, SBC_A, INC_A, NOP,
		BEQ, NOP, NOP, NOP, NOP, SBC_ZX, INC_ZX, NOP, SED, SBC_AY, NOP, NOP, NOP, SBC_AX, INC_AX, NOP
	};
	void (*eval_func[OPCODE_COUNT])(void) = {
#define X(opcode, op_fn, str_lit) op_fn,
		OPCODES_LIST
#undef X
	};
	struct timeval p_time;
	long int l_cycle;
	(void)arg;

	init_ccrom();

	/* Shutdown c_state is 0 */
	while (c_state) {
		/*
		 * The clock rate is set to 1Mhz, or 1 instruction/microsecond
		 *
		 * This hack is used instead of usleep() because usleep would cause a
		 * 1us delay in addition to the time taken to evaluate the instruction,
		 * whereas this timer counts during evaluation.
		 *
		 * Right now, each instruction takes 1 clock cycle (or more, if slow).
		 * This is not accurate to a real 6502, where the instruction and
		 * addressing mode impact the number of clock cycles. This may be
		 * implemented in the future.
		 */
		l_cycle = p_time.tv_usec;
		gettimeofday(&p_time, 0);
		if (l_cycle == p_time.tv_usec) continue;

		if (read_mem(0x2001)) {
			zmem(0x2001);
			restart_gpu();
		} else if (read_mem(0x4000)) {
			printf("Breaking at address 0x%x\n", read_mem16(s + 0x103) - 1);
			c_state = PRG_DBG;
		} else if (read_mem(0x4018)) {
			zmem(0x4018);
			print_buffer();
			continue;
		} else if (read_mem(0x4019)) {
			zmem(0x4019);
			print_number();
			continue;
		}

		if (c_state == PRG_RN) {
			(*eval_func[t6502[*pc++]])();
		} else {
			shell_prompt();
			continue;
		}
	}

	return 0;
}

void
stop_cpu(void) {
	c_state = CPU_STP;
}

void
init_ccrom(void) {
	/* Default brk handler */
	const u8 ccrom[] = { 0x48, 0xa9, 0x01, 0x8d, 0x00, 0x40, 0x68, 0x40 };

	write_nmem(0x7ff8, ccrom, 8);
	write_mem16(0xfffe, 0x7ff8);
}

