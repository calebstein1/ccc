#include <stdio.h>
#include <stdint.h>
#include <string.h>
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

// Default brk handler
uint8_t ccrom[] = { 0x48, 0xa9, 0x01, 0x8d, 0x00, 0x40, 0x68, 0x40 };

cpu_state c_state = BOOT;

void init_ccrom() {
    memcpy(&prg_ram[0x7ff8], ccrom, 8);
    prg_ram[0xfffe] = 0xf8;
    prg_ram[0xffff] = 0x7f;
}

void *start_cpu() {
    struct timeval p_time = {};
    uint32_t l_cycle = 0;

    init_ccrom();

    // Shutdown c_state is 0
    while (c_state) {
        l_cycle = p_time.tv_usec;
        gettimeofday(&p_time, 0);
        if (l_cycle == p_time.tv_usec) continue;

        if (prg_ram[0x4000]) {
            uint8_t low = *(prg_ram + s + 0x103);
            uint8_t hi = *(prg_ram + s + 0x104);
            printf("Breaking at address 0x%x\n", MAKE_WORD - 1);
            c_state = PRG_DBG;
        } else if (prg_ram[0x4018]) {
            prg_ram[0x4018] = 0;
            print_buffer();
            continue;
        } else if (prg_ram[0x4019]) {
            prg_ram[0x4019] = 0;
            print_number();
            continue;
        }

        if(c_state == PRG_RN) {
            (*eval_func[t6502[*pc++]])();
        } else {
            fputs("$ ", stdout);
            shell_prompt();
            continue;
        }
    }

    return 0;
}

void stop_cpu() {
    c_state = CPU_STP;
}