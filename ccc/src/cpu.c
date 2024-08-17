#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

#include "globals.h"
#include "cpu.h"
#include "opcodes.h"

// RAM, Program Counter, and Stack Pointer
uint8_t prg_ram[0xffff];
uint8_t *pc = &prg_ram[0x8000];
uint8_t s = 0xff;

// CPU Registers
uint8_t a, x, y;
uint8_t p;

uint8_t shutdown = 0;
uint8_t debug = 0;
uint8_t m6502 = 1;

void start_cpu() {
    struct timeval p_time = {};
    uint32_t l_cycle = 0;

    while (!shutdown) {
        l_cycle = p_time.tv_usec;
        gettimeofday(&p_time, 0);
        if (l_cycle == p_time.tv_usec) continue;

        if (debug) printf("%s\n", str_tbl[t6502[*pc]]);
        if (m6502) {
            (*eval_func[t6502[*pc++]])();
        } else {
            (*eval_func[*pc++])();
        }
        if (debug && pc < prg_ram + 0xff00) {
            print_registers();
            getchar();
        }
    }
}

void stop_cpu() {
    shutdown = 1;
}

void print_registers() {
    printf("a: %d\nx: %d\ny: %d\np: %d%d1%d%d%d%d%d\n   NV1BDIZC\n",
           a, x, y, GET_N, GET_V, GET_B, GET_D, GET_I, GET_Z, GET_C);
}