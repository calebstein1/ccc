#include <stdio.h>
#include <stdint.h>

#include "globals.h"

// RAM, Program Counter, and Stack Pointer
uint8_t prg_ram[0xffff] = {};
uint8_t *pc = &prg_ram[0x8000];
uint8_t *sp = prg_ram;

// CPU Registers
uint8_t a = 0x0, x = 0x0, y = 0x0;
uint8_t p = 0x0;

void run_prg() {
    while (*pc != 0x0) {
        (*eval_func[*pc++])();
    }
}
