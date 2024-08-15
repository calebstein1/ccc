#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

#include "globals.h"
#include "cpu.h"
#include "opcodes.h"

// RAM, Program Counter, and Stack Pointer
uint8_t prg_ram[0xffff];
uint8_t *pc = &prg_ram[0xff00];
uint8_t s;

// CPU Registers
uint8_t a, x, y;
uint8_t p;

uint8_t shutdown = 0;
uint8_t debug = 0;

void start_cpu() {
    struct timeval p_time = {};
    uint32_t l_cycle = 0;

    while (!shutdown) {
        l_cycle = p_time.tv_usec;
        gettimeofday(&p_time, 0);
        if (l_cycle == p_time.tv_usec) continue;

        if (debug) printf("%s\n", str_tbl[*pc]);
        (*eval_func[*pc++])();
        if (debug) {
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