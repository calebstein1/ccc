#include <stdio.h>

#include "prg.h"

// RAM, Program Counter, and Stack Pointer
unsigned char prg_ram[0xffff] = {};
unsigned char *pc = &prg_ram[0x8000];
unsigned char *s = &prg_ram[0x0100];

// CPU Registers
unsigned char a = 0x0, x = 0x0, y = 0x0;
unsigned char p = 0x0;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Please supply a single program file\n");
        return -1;
    }
    if (parse_prg(argv[1])) {
        fprintf(stderr, "Failed to load program\n");
        return -1;
    }

    return 0;
}
