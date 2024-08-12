#include <stdio.h>

#include "globals.h"
#include "prg.h"

// RAM, Program Counter, and Stack Pointer
unsigned char prg_ram[0xffff] = {};
unsigned char *pc = &prg_ram[0x8000];
unsigned char *sp = prg_ram;

// CPU Registers
unsigned char a = 0x0, x = 0x0, y = 0x0;
unsigned char p = 0x0;

int main(int argc, char **argv) {
    if (argc != 2) {
        fputs("Please supply a single program file\n", stderr);
        return -1;
    }
    if (load_prg(argv[1])) {
        fputs("Failed to load program\n", stderr);
        return -1;
    }

    while (pc < &prg_ram[0xffff]) {
        (*eval_func[*pc])();
        pc++;
    }

    printf("a: %d\nx: %d\ny: %d\n", a, x, y);
    return 0;
}
