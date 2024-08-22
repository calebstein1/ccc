#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

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

cpu_state state = BOOT;

void start_cpu() {
    struct timeval p_time = {};
    uint32_t l_cycle = 0;

    // Shutdown state is 0
    while (state) {
        l_cycle = p_time.tv_usec;
        gettimeofday(&p_time, 0);
        if (l_cycle == p_time.tv_usec) continue;

        if (prg_ram[0x4000]) {
            state = PRG_DBG;
        } else if (prg_ram[0x4018]) {
            prg_ram[0x4018] = 0;
            print_buffer();
            continue;
        } else if (prg_ram[0x4019]) {
            prg_ram[0x4019] = 0;
            print_number();
            continue;
        }

        if(state == PRG_RN) {
            (*eval_func[t6502[*pc++]])();
        } else {
            fputs("$ ", stdout);
            shell_prompt();
            continue;
        }

    }
}

void stop_cpu() {
    state = SHUTDWN;
}