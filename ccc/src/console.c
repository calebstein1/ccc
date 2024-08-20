#include <stdio.h>

#include "globals.h"
#include "console.h"

void print_buffer() {
    printf("%s", &prg_ram[0x4020]);
}

void print_number() {
    printf("%d", prg_ram[0x4020]);
}