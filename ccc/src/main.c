#include <stdio.h>
#include <stdint.h>

#include "globals.h"
#include "prg.h"

// RAM, Program Counter, and Stack Pointer
uint8_t prg_ram[0xffff] = {};
uint8_t *pc = &prg_ram[0x8000];
uint8_t *sp = prg_ram;

// CPU Registers
uint8_t a = 0x0, x = 0x0, y = 0x0;
uint8_t p = 0x0;

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
        (*eval_func[*pc++])();
    }

    printf("a: %d\nx: %d\ny: %d\n", a, x, y);
    return 0;
}
