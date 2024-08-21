#include <stdio.h>

#include "globals.h"
#include "console.h"
#include "cpu.h"

void print_registers() {
    printf("a: %d\nx: %d\ny: %d\npc: 0x%x\ns: 0x%x\np: %d%d%d%d%d%d%d\n   NVBDIZC\n",
           a, x, y, (uint16_t)(pc - prg_ram), s, GET_N, GET_V, GET_B, GET_D, GET_I, GET_Z, GET_C);
}

void print_buffer() {
    printf("%s", &prg_ram[0x4020]);
}

void print_number() {
    printf("%d\n", (uint16_t)(prg_ram[0x4020] + (prg_ram[0x4021] ? prg_ram[0x4021] * 0x100 : 0)));
}