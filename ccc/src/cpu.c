#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

#include "globals.h"
#include "console.h"
#include "shell.h"
#include "cpu.h"
#include "opcodes.h"

// RAM, Program Counter, and Stack Pointer
uint8_t prg_ram[0x10000];
uint8_t *pc = &prg_ram[0x8000];
uint8_t s = 0xff;

// CPU Registers
uint8_t a, x, y;
uint8_t p = 32;

uint8_t prg_loaded = 0;
uint8_t shutdown = 0;
uint8_t debug = 0;

void start_cpu() {
    struct timeval p_time = {};
    uint32_t l_cycle = 0;

    while (!shutdown) {
        l_cycle = p_time.tv_usec;
        gettimeofday(&p_time, 0);
        if (l_cycle == p_time.tv_usec) continue;

        if (prg_ram[0x4000]) {
            fputs("$ ", stdout);
            shell_prompt();
            continue;
        } else if (prg_ram[0x4018]) {
            prg_ram[0x4018] = 0;
            print_buffer();
            continue;
        } else if (prg_ram[0x4019]) {
            prg_ram[0x4019] = 0;
            print_number();
            continue;
        }

        if(!prg_loaded) {
            fputs("$ ", stdout);
            shell_prompt();
            continue;
        }

        (*eval_func[t6502[*pc++]])();
    }
}

void stop_cpu() {
    shutdown = 1;
}