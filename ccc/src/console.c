#include <stdio.h>

#include "globals.h"
#include "console.h"

void print_buffer() {
    printf("%s\n", &prg_ram[0x4020]);
}