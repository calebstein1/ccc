#include <stdio.h>
#include <stdint.h>

#include "console.h"
#include "cpu.h"

void print_buffer(void) {
    printf("%s", &prg_ram[0x4020]);
}

void print_number(void) {
    printf("%d\n", (uint16_t)(prg_ram[0x4020] + (prg_ram[0x4021] ? prg_ram[0x4021] * 0x100 : 0)));
}

